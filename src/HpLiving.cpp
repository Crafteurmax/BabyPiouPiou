#include "HpLiving.h"


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

float HpLiving::getHealth() const
{
	return _health;
}

bool HpLiving::takeHit(sf::Vector2f bulletPos)
{
	if (CoolMath::norme(getOffsetPosition() - bulletPos) > hitBoxSize) return false;
	damage(10);
	return true;
}
