#pragma once

#include "SFML/Graphics.hpp"
#include "Player.h"
#include "Background.h"
#include "Projectile.h"
#include "Enemy.h"
#include "Level.h"


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
	Level _level{ "level0" };
	bool _levelEnd = false;

	std::vector<std::unique_ptr<Projectile>> bullets;
	std::vector<std::unique_ptr<Enemy>> _currentEnemies;

	void processEvents();
	void update(sf::Time delatTime);
	void render();

};