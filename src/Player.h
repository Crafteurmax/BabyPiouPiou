#ifndef PLAYER
#define PLAYER

#include "HpLiving.h"

#include <array>

class Player : public HpLiving {
public:
	Player();
	void update(const sf::Time& elapsedTime, sf::Vector2f playerPos, sf::Vector2f screenSize) override;
	void handlePlayerInput(const sf::Keyboard::Key& key, const bool& isPressed);

private:
	sf::Vector2f _movement;
	std::array<bool, 4> isMoving = { false, false, false, false };
	float speed = 100;
	float invSqr2 = 0.707106f;
};


#endif //PLAYER
