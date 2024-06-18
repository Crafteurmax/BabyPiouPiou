#ifndef PLAYER
#define PLAYER

#include "HpLiving.h"
#include "CoolMath.h"

#include <array>

class Player : public HpLiving {
public:
	Player();
	void update(const sf::Time& elapsedTime, sf::Vector2f playerPos, sf::Vector2f screenSize) override;
	void handlePlayerInput(const sf::Keyboard::Key& key, const bool& isPressed);
	float getCooldown();
	void resetCooldown();
	bool takeHit(sf::Vector2f bulletPos);

private:
	sf::Vector2f _movement;
	std::array<bool, 4> isMoving = { false, false, false, false };
	float speed = 100;
	float invSqr2 = 0.707106f;
	float normalShootCooldown;
	float hitBoxSize = 10;
};


#endif //PLAYER
