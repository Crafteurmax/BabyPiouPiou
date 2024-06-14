#include "HpLiving.h"


//TODO IMPLEMENT
HpLiving::HpLiving(const sf::Vector2f& size, float startHP, const std::string& texture) :
	DrawableObject(size, texture),
	_health(startHP)
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
