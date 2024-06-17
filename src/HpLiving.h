#pragma once

#include "DrawableObject.h"
#include "pugixml.hpp"

class HpLiving : public DrawableObject {
public:
	HpLiving(const HpLiving& other) = default;

	HpLiving(const std::string& label, const sf::Vector2f& size, float startHP, const std::string& texture);
	explicit HpLiving(const pugi::xml_node& node);
	~HpLiving() override = default;
	bool isDead() const;
	void damage(float amount);
	void update(const sf::Time& elapsedTime) override;
	float getHealth() const;
private:
	float _health;
};