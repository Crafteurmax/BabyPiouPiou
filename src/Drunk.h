#ifndef DRUNK
#define DRUNK

#include "Enemy.h"

class Drunk : public Enemy {
public:
	void update(const sf::Time& elapsedTime) override;
private:
	float angularVelocity;
	float currentAngle;
	float radius;
	sf::Vector2f movingCenter;
};


#endif //DRUNK