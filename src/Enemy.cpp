#include "Enemy.h"
#include "pugixml.hpp"

Enemy::Enemy(const pugi::xml_node& node):
	HpLiving(node)
{
	std::cout << "Called 1 new : " << getLabel() << std::endl;

	for (const auto& child : node.children()) {
		_spellcards.emplace_back(child);
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
	setLabel(label);
	_position = position;
}