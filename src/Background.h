#ifndef BACKGROUND
#define BACKGROUND


#include "DrawableObject.h"
#include "pugixml.hpp"


#include <array>



constexpr float SIZE = 128.0f;


class Background : public DrawableObject {
public:
	Background(sf::Vector2f screenSize);
	void update(const sf::Time& elapsedTimee) override;
	void handlePlayerInput(const sf::Keyboard::Key& key, const bool& isPressed);
	void draw(sf::RenderWindow& window) override;

private:


	sf::Vector2f _movement;
	std::array<bool, 4> isMoving = { false, false, false, false };
	float speed = -5;
	float invSqr2 = 0.707106f;

	DrawableObject midLayer;
};

#endif BACKGROUND