#include "Tank.h"

Tank::Tank(pugi::xml_node& node) :
	Enemy(node)
{
	//_label = node.attribute("label").as_string();
	//_size = sf::Vector2f(
	//	node.attribute("size_x").as_float(),
	//	node.attribute("size_y").as_float()
	//);

}

void Tank::update(const sf::Time& elapsedTime) {

}