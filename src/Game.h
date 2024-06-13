#pragma once

#include "SFML/Graphics.hpp"
class Game {
public :
	Game();
	void run();

private:
	sf::RenderWindow		mWindow{ sf::VideoMode{640, 480}, "SFML Application", sf::Style::Close };
	static const sf::Time	TimePerFrame;
	bool _isRunning = false;

	void processEvents();
	void update(sf::Time delatTime);
	void render();

};