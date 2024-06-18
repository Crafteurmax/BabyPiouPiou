#include "Projectile.h"
#include <iostream>

Projectile::Projectile(const pugi::xml_node& node) : DrawableObject(node),
_beginLifetime(node.attribute("lifetime").as_float()),
beginVit(sf::Vector2f{ node.attribute("vel_x").as_float(), node.attribute("vel_y").as_float() }),
beginAcc(sf::Vector2f{ node.attribute("acc_x").as_float(), node.attribute("acc_y").as_float() }),
beginAco(sf::Vector2f{ node.attribute("aco_x").as_float(), node.attribute("aco_y").as_float() }),
deltaPos(sf::Vector2f{ node.attribute("delta_x").as_float(), node.attribute("delta_y").as_float() })
{
	//delta pos
	_projectileType = ProjectileType::FROM_ENEMY;
	reset({});
}

Projectile::Projectile(float lifetime, ProjectileType projectileType, sf::Vector2f pos,
	sf::Vector2f vit, sf::Vector2f acc, sf::Vector2f aco) :
	DrawableObject("projectile", {32.f,32.f}, "bullet.png"),
	_projectileType(projectileType), _beginLifetime(lifetime),
	beginVit(vit), beginAcc(acc), beginAco(aco)
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

void Projectile::reset(const sf::Vector2f& refPos) {
	_currentLifetime = _beginLifetime;
	currentVit = beginVit;
	currentAcc = beginAcc;
	currentAco = beginAco;
	const auto proj_pos = deltaPos + refPos;
	setPosition(proj_pos);
}