#ifndef PLAYER
#define PLAYER

#include "HpLiving.h"

class Player : public HpLiving {
public:
	Player();
	void update(const sf::Time& elapsedTimee) override;
	void handlePlayerInput(const sf::Keyboard::Key& key, const bool& isPressed);

private:
	bool isMoving[4] = { false, false, false, false };
	float speed = 100;
	float invSqr2 = 0.707106f;
};


#endif //PLAYER
