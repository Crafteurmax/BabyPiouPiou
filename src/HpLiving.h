#ifndef HP_LIVING
#define HP_LIVING

#include "DrawableObject.h"
#include "pugixml.hpp"
#include "CoolMath.h"

class HpLiving : public DrawableObject {
public:
	HpLiving(const HpLiving& other) = default;

	HpLiving(const std::string& label, const sf::Vector2f& size, float startHP, const std::string& texture);
	explicit HpLiving(const pugi::xml_node& node);
	~HpLiving() override = default;
	bool isDead() const;
	void damage(float amount);
	float getHealth() const;
	bool takeHit(sf::Vector2f bulletPos);

private:
	float _health;
	float hitBoxSize = 10;
};

#endif