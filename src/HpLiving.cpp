#include "HpLiving.h"


//TODO IMPLEMENT
HpLiving::HpLiving(sf::Vector2f size, float startHP) :
	DrawableObject(size)
{
	_health = startHP;
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
