#ifndef DRUNK
#define DRUNK

#include "Enemy.h"
#include "pugixml.hpp"

class Drunk : public Enemy {
public:
	explicit Drunk(pugi::xml_node& node);
	void update(const sf::Time& elapsedTime) override;
private:
	float angularVelocity;
	float currentAngle;
	float radius;
	sf::Vector2f movingCenter;
};


#endif //DRUNK