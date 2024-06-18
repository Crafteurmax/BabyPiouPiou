#include "Enemy.h"

Enemy::Enemy(const pugi::xml_node& node): 
	HpLiving(node)
{
	std::cout << "Called 1 new : " << getLabel() << std::endl;

	for (const auto& child : node.children()) {
		_spellcards.emplace_back(child);
	}


}

void Enemy::update(const sf::Time& elapsedTime, sf::Vector2f playerPos, sf::Vector2f screenSize) {


	// on cherche la direction vers le joueur
	sf::Vector2f direction = playerPos - getOffsetPosition();
	float norme = CoolMath::norme(direction);
	// si l'on est a bonne distance on ne fait rien
	if (norme < distance * 1.05 && norme> distance * 0.95) return;

	direction /= norme;
	// si le joueur est trop loin on avance vers lui, la destination est toujours correcte
	if (norme > distance)
	{
		_position += direction * elapsedTime.asSeconds() * speed;
		HpLiving::update(elapsedTime, playerPos, screenSize);
		return;
	}

	// sinon on doit reculer, la destination n'est pas toujours correcte
	direction *= -1.f;
	sf::Vector2f destination = _position + direction * elapsedTime.asSeconds() * speed;
	// on teste si l'un deux deux composant dépasse
	bool flowX = destination.x < 0 || destination.x > screenSize.x - _size.x;
	bool flowY = destination.y < 0 || destination.y > screenSize.y - _size.y;

	// 4 scénario
	// le meilleur, rien ne bloque on recule juste
	if (!flowX && !flowY) _position = destination;
	// le pire, on est dans un coin, on ne bouge pas
	else if (flowX && flowY) return;
	// si on dépasse en X, on se déplace en Y
	else if (flowX) {
		if (_position.y + direction.y * speed * elapsedTime.asSeconds() < 0)  _position.y = 0;
		if (_position.y + direction.y * speed * elapsedTime.asSeconds() > screenSize.y - _size.y)  _position.y = screenSize.y - _size.y;
		else _position.y += direction.y * speed * elapsedTime.asSeconds();
	}
	// l'autre cas (pas besoin de tester car c'est le dernier possible)
	else {
		if (_position.x + direction.x * speed * elapsedTime.asSeconds() < 0)  _position.x = 0;
		if (_position.x + direction.x * speed * elapsedTime.asSeconds() > screenSize.x - _size.x)  _position.x = screenSize.x - _size.x;
		else _position.x += direction.x * speed * elapsedTime.asSeconds();
	}



	HpLiving::update(elapsedTime, playerPos, screenSize);
}

void Enemy::setupInstance(const std::string& label, const sf::Vector2f& position) {
	setLabel(label);
	_position = position;
}

void Enemy::trySpawnProjectiles(const sf::Time& elapsedTime, std::vector<std::shared_ptr<Projectile>>& projectiles)
{

	_currentSpellTime -= elapsedTime.asSeconds();
	if (_currentSpellTime > 0) {
		return;
	}

	if (_spellcards.empty()) {
		std::cerr << "ALERT NO SPELL CARD FOR ENEMY : " << getLabel() << std::endl;
	}

	auto randomIt = _spellcards.begin();
	std::advance(randomIt, CoolMath::randomInt(static_cast<int>(_spellcards.size()))-1);

	_currentSpellTime = randomIt->spawnSpell(projectiles, _position);
}
