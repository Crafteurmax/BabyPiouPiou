#pragma once

#include "DrawableObject.h"

class HpLiving : public DrawableObject {
public: 
	HpLiving() = default;
	~HpLiving() override = default;
	bool isDead() const;
	void damage();
	void update() override = 0;
private:
	float _health;
};