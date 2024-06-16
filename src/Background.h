
#include "DrawableObject.h"
#include "pugixml.hpp"
#define SIZE 128


class Background : public DrawableObject {
public:
	Background();
	void update(const sf::Time& elapsedTimee) override;
	void handlePlayerInput(const sf::Keyboard::Key& key, const bool& isPressed);
	void draw(sf::RenderWindow& window) override;

private:
	sf::Vector2f _movement;
	bool isMoving[4] = { false, false, false, false };
	float speed = -5;
	float invSqr2 = 0.707106f;

	DrawableObject midLayer{ "sky2", { SIZE,SIZE }, "sky2.png" , 12};
};