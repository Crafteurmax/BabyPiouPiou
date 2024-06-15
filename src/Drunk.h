#ifndef DRUNK
#define DRUNK

#include "Enemy.h"
#include "pugixml.hpp"

class Drunk : public Enemy {
public:
	explicit Drunk(pugi::xml_node& node);
	Drunk(const Drunk& prefabDrunk, sf::Vector2f pos, float startAngle, std::string label);
	void update(const sf::Time& elapsedTime) override;
private:
	float angularVelocity = 10;
	float currentAngle = 0;
	float radius = 100;
	sf::Vector2f movingCenter;
};


#endif //DRUNK