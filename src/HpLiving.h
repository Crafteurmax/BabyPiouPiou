#pragma once

#include "DrawableObject.h"

class HpLiving : public DrawableObject {
public: 
	HpLiving(sf::Vector2f size);
	~HpLiving() override = default;
	bool isDead() const;
	void damage();
	void update(const sf::Time& elapsedTime) override;
private:
	float _health;
};