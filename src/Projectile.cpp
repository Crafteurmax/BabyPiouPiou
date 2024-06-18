#include "Projectile.h"
#include <iostream>

Projectile::Projectile(const pugi::xml_node& node) : DrawableObject(node) {}

Projectile::Projectile(float _lifetime, ProjectileType _projectileType, sf::Vector2f pos,
	sf::Vector2f vit, sf::Vector2f acc, sf::Vector2f aco) :
	DrawableObject("projectile", {32.f,32.f}, "bullet.png"),
	_lifetime(_lifetime), _projectileType(_projectileType),
	vit(vit),acc(acc),aco(aco)
{
	setPosition(pos);
}

void Projectile::update(const sf::Time& elapsedTime, sf::Vector2f playerPos, sf::Vector2f screenSize)
{
	_lifetime -= elapsedTime.asSeconds();

	acc += aco * elapsedTime.asSeconds();
	vit += acc * elapsedTime.asSeconds();
	_position += vit * elapsedTime.asSeconds();
	_sprite.setPosition(_position);
}

void Projectile::setupInstance(sf::Vector2f origin)
{
	_position += origin;
}
