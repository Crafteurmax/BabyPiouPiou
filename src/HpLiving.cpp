#include "HpLiving.h"


//TODO IMPLEMENT
HpLiving::HpLiving(const std::string& label, const sf::Vector2f& size, float startHP, const std::string& texture) :
	DrawableObject(label, size, texture),
	_health(startHP)
{
}

HpLiving::HpLiving(pugi::xml_node& node) :
	DrawableObject(node),
	_health(node.attribute("health").as_float())
{
	
}

//HpLiving::~HpLiving()
//{
//}

bool HpLiving::isDead() const
{
	return _health <= 0;
}

void HpLiving::damage(float amount)
{
	_health -= amount;
}

void HpLiving::update(const sf::Time& elapsedTime)
{
}

float HpLiving::getHealth()
{
	return _health;
}
