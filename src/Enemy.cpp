#include "Enemy.h"
#include "pugixml.hpp"

Enemy::Enemy(const pugi::xml_node& node):
	HpLiving(node)
{
	for (const auto& child : node.children()) {
		_spellcards.push_back(SpellCard(child));
	}


}

Enemy::Enemy(const Enemy& prefab, const std::string& label) :
	HpLiving(prefab,label)
{
}
void Enemy::update(const sf::Time& elapsedTime) {
	//TODO
}

void Enemy::setupInstance(const std::string& label, const sf::Vector2f& position) {
	_label = label;
	_position = position;
}