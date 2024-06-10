#pragma once

#include "DrawableObject.h"

class HpLiving : public DrawableObject {
public: 
	HpLiving() = default;
	~HpLiving() override = default;
	bool isDead() const;
	void damage();

private:
	float _health;
};