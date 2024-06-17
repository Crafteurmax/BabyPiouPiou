#include "HpLiving.h"


//TODO IMPLEMENT
HpLiving::HpLiving(const std::string& label, const sf::Vector2f& size, float startHP, const std::string& texture) :
	DrawableObject(label, size, texture),
	_health(startHP)
{
}

HpLiving::HpLiving(const pugi::xml_node& node) :
	DrawableObject(node),
	_health(node.attribute("health").as_float())
{

}

bool HpLiving::isDead() const
{
	return _health <= 0;
}

void HpLiving::damage(float amount)
{
	_health -= amount;
}

void HpLiving::update(const sf::Time& elapsedTime, sf::Vector2f playerPos, sf::Vector2f screenSize)
{
	//TODO ADD STUFF

	DrawableObject::update(elapsedTime, playerPos, screenSize);
}

float HpLiving::getHealth() const
{
	return _health;
}
