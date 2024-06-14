#include "Drunk.h"
#include "pugixml.hpp"

Drunk::Drunk(pugi::xml_node& node) :
	Enemy(node)
{
}

void Drunk::update(const sf::Time& elapsedTime)
{
	currentAngle += angularVelocity * elapsedTime.asSeconds();

	_position = movingCenter + sf::Vector2f(cos(currentAngle), sin(currentAngle))*radius;
}
