#include "Drunk.h"

Drunk::Drunk(pugi::xml_node& refNode) :
	Enemy(refNode)
{

}

void Drunk::update2(const sf::Time& elapsedTime, sf::Vector2f playerPos, sf::Vector2f screenSize)
{
	// on cherche la direction vers le joueur
	sf::Vector2f direction = playerPos - movingCenter;
	float norme = CoolMath::norme(direction);
	// si l'on est a bonne distance on ne fait rien
	if (norme < distance * 1.05 && norme> distance * 0.95) return;

	direction /= norme;
	// si le joueur est trop loin on avance vers lui, la destination est toujours correcte
	if (norme > distance)
	{
		movingCenter += direction * elapsedTime.asSeconds() * speed;
		update(elapsedTime);
		return;
	}

	// sinon on doit reculer, la destination n'est pas toujours correcte
	direction *= -1.f;
	sf::Vector2f destination = movingCenter + direction * elapsedTime.asSeconds() * speed;
	// on teste si l'un deux deux composant dépasse
	bool flowX = destination.x < radius || destination.x > screenSize.x - (_size.x + radius);
	bool flowY = destination.y < radius || destination.y > screenSize.y - (_size.y + radius);

	// 4 scénario
	// le meilleur, rien ne bloque on recule juste
	if (!flowX && !flowY) movingCenter = destination;
	// le pire, on est dans un coin, on ne bouge pas
	else if (flowX && flowY) return;
	// si on dépasse en X, on se déplace en Y
	else if (flowX) {
		if (movingCenter.y + direction.y * speed * elapsedTime.asSeconds() < 0)  movingCenter.y = 0;
		if (movingCenter.y + direction.y * speed * elapsedTime.asSeconds() > screenSize.y - _size.y)  movingCenter.y = screenSize.y - _size.y;
		else movingCenter.y += direction.y * speed * elapsedTime.asSeconds();
	}
	// l'autre cas (pas besoin de tester car c'est le dernier possible)
	else {
		if (movingCenter.x + direction.x * speed * elapsedTime.asSeconds() < 0)  movingCenter.x = 0;
		if (movingCenter.x + direction.x * speed * elapsedTime.asSeconds() > screenSize.x - _size.x)  movingCenter.x = screenSize.x - _size.x;
		else movingCenter.x += direction.x * speed * elapsedTime.asSeconds();
	}

	update(elapsedTime);
}

void Drunk::update(const sf::Time& elapsedTime)
{
	currentAngle += angularVelocity * elapsedTime.asSeconds();

	_position = movingCenter + sf::Vector2f(cos(currentAngle), sin(currentAngle)) * radius;

	HpLiving::update(elapsedTime);
}
