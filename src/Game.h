#pragma once

#include "SFML/Graphics.hpp"
#include "Player.h"
#include <Background.h>
class Game {
public :
	Game();
	void run();

private:
	sf::RenderWindow		mWindow{ sf::VideoMode{640, 480}, "BABY", sf::Style::Close };
	Player					player{};
	static const sf::Time	TimePerFrame;
	bool					_isRunning = false;

	Background				bg;

	void processEvents();
	void update(sf::Time delatTime);
	void render();

};