#pragma once

#include "DrawableObject.h"

class HpLiving : public DrawableObject {
public: 
	HpLiving(const sf::Vector2f& size, float startHP, const std::string& texture);
	~HpLiving() override = default;
	bool isDead() const;
	void damage(float amount);
	void update(const sf::Time& elapsedTime) override;
	float getHealth();
private:
	float _health;
};