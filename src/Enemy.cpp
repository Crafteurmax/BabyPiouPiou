#include "Enemy.h"
#include "pugixml.hpp"

Enemy::Enemy(const pugi::xml_node& node):
	HpLiving(node)
{
	for (const auto& child : node.children()) {
		_spellcards.push_back(SpellCard(child));
	}


}

void Enemy::update(const sf::Time& elapsedTime) {
	//TODO
}