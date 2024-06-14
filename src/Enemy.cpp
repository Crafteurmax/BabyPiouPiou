#include "Enemy.h"
#include "pugixml.hpp"

Enemy::Enemy(pugi::xml_node& node):
	HpLiving(node)
{
}

void Enemy::update(const sf::Time& elapsedTime) {
	//TODO
}