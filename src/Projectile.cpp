#include "Projectile.h"
#include <iostream>

Projectile::Projectile(const pugi::xml_node& node) : DrawableObject(node),
_currentLifetime(node.attribute("lifetime").as_float()),
currentVit(sf::Vector2f{ node.attribute("vel_x").as_float(), node.attribute("vel_y").as_float() }),
currentAcc(sf::Vector2f{ node.attribute("acc_x").as_float(), node.attribute("acc_y").as_float() }),
currentAco(sf::Vector2f{ node.attribute("aco_x").as_float(), node.attribute("aco_y").as_float() }),
deltaPos(sf::Vector2f{ node.attribute("delta_x").as_float(), node.attribute("delta_y").as_float() })
{
	//delta pos
	_projectileType = ProjectileType::FROM_ENEMY;
	reset({});
}

Projectile::Projectile(float lifetime, ProjectileType projectileType, sf::Vector2f pos,
	sf::Vector2f vit, sf::Vector2f acc, sf::Vector2f aco) :

	DrawableObject("projectile", {32.f,32.f}, "bulletPlayer.png", pos),
	_projectileType(projectileType), _currentLifetime(lifetime),
	currentVit(vit), currentAcc(acc), currentAco(aco)
{
	reset(pos);
}

void Projectile::update(const sf::Time& elapsedTime, sf::Vector2f playerPos, sf::Vector2f screenSize)
{
	_currentLifetime -= elapsedTime.asSeconds();

	currentAcc += currentAco * elapsedTime.asSeconds();
	currentVit += currentAcc * elapsedTime.asSeconds();
	_position += currentVit * elapsedTime.asSeconds();
	_sprite.setPosition(_position);
}


bool Projectile::isDead() const {
	return _currentLifetime <= 0.0f;
}

//Reinitialiser la position du projectile par rapport à l'enemi
void Projectile::reset(const sf::Vector2f& refPos) {
	const auto proj_pos = deltaPos + refPos;
	setPosition(proj_pos);
}

void Projectile::kill()
{
	_currentLifetime = 0.f;
}

ProjectileType Projectile::getType() const
{
	return _projectileType;
}
