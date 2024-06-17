#ifndef DRUNK
#define DRUNK

#include "Enemy.h"
#include "pugixml.hpp"
#include "CoolMath.h"

class Drunk : public Enemy {
public:
	Drunk(const Drunk& other) = default;
	explicit Drunk(pugi::xml_node& node);
	void update2(const sf::Time& elapsedTime, sf::Vector2f playerPos, sf::Vector2f screenSize) override;
	void update(const sf::Time& elapsedTime) override;
private:
	float angularVelocity = 20;
	float currentAngle = 0;
	float radius = 100;
	sf::Vector2f movingCenter;
};


#endif //DRUNK