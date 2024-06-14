#pragma once

#include "DrawableObject.h"
#include "pugixml.hpp"

class HpLiving : public DrawableObject {
public:
	HpLiving(const std::string& label, const sf::Vector2f& size, float startHP, const std::string& texture);
	HpLiving(pugi::xml_node& node);
	~HpLiving() override = default;
	bool isDead() const;
	void damage(float amount);
	void update(const sf::Time& elapsedTime) override;
	float getHealth();
private:
	float _health;
};