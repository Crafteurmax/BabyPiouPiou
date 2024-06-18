#include "Projectile.h"
#include <iostream>

Projectile::Projectile(const pugi::xml_node& node) : DrawableObject(node),
_lifetime(node.attribute("lifetime").as_float()),
vit(sf::Vector2f{ node.attribute("vel_x").as_float(), node.attribute("vel_y").as_float() }),
acc(sf::Vector2f{ node.attribute("acc_x").as_float(), node.attribute("acc_y").as_float() }),
aco(sf::Vector2f{ node.attribute("aco_x").as_float(), node.attribute("aco_y").as_float() })
{
	_projectileType = ProjectileType::FROM_ENEMY;
}

Projectile::Projectile(float _lifetime, ProjectileType _projectileType, sf::Vector2f pos,
	sf::Vector2f vit, sf::Vector2f acc, sf::Vector2f aco) :
	DrawableObject("projectile", {32.f,32.f}, "bullet.png", pos),
	_lifetime(_lifetime), _projectileType(_projectileType),
	vit(vit),acc(acc),aco(aco)
{
}

void Projectile::update(const sf::Time& elapsedTime, sf::Vector2f playerPos, sf::Vector2f screenSize)
{
	_lifetime -= elapsedTime.asSeconds();

	acc += aco * elapsedTime.asSeconds();
	vit += acc * elapsedTime.asSeconds();
	_position += vit * elapsedTime.asSeconds();
	_sprite.setPosition(_position);
}


bool Projectile::isDead() const {
	return _lifetime <= 0.0f;
}