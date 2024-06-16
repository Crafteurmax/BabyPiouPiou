#include "Projectile.h"
#include <iostream>

Projectile::Projectile(const pugi::xml_node& node) : DrawableObject(node) {
	//TODO
}

Projectile::Projectile(float _lifetime, ProjectileType _projectileType, sf::Vector2f pos,
	sf::Vector2f vit, sf::Vector2f acc, sf::Vector2f aco) :
	DrawableObject("projectile", {160.f,160.f}, "chat.png"),
	_lifetime(_lifetime), _projectileType(_projectileType),
	vit(vit),acc(acc),aco(aco)
{
	setPosition(pos);
}

void Projectile::update(const sf::Time& elapsedTime)
{
	_lifetime -= elapsedTime.asSeconds();

	acc += aco * elapsedTime.asSeconds();
	vit += acc * elapsedTime.asSeconds();
	_position += vit * elapsedTime.asSeconds();
	_sprite.setPosition(_position);

	//std::cout << "update bullet " << _position.x << "," << _position.y << std::endl;
}
