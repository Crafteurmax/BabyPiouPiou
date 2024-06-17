#ifndef DRUNK
#define DRUNK

#include "Enemy.h"
#include "pugixml.hpp"
#include "CoolMath.h"

class Drunk : public Enemy {
public:
	Drunk(const Drunk& other) = default;
	explicit Drunk(const pugi::xml_node& node);
	void update(const sf::Time& elapsedTime, sf::Vector2f playerPos, sf::Vector2f screenSize) override;
	inline std::unique_ptr<Enemy> clone() const override { return std::make_unique<Drunk>(*this); }

	void setupInstance(const std::string& label, const sf::Vector2f& position) override;
private:
	float currentAngle = 0;
	float angularVelocity = 20;
	float radius = 100;
	sf::Vector2f movingCenter;
};


#endif //DRUNK