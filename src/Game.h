#pragma once

#include "SFML/Graphics.hpp"
#include "Player.h"
#include "Background.h"
#include "Projectile.h"
#include "Enemy.h"
#include "Level.h"


constexpr int WINDOW_WIDTH = 1000;
constexpr int WINDOW_HEIGHT = 800;


class Game {
public :
	Game();
	void run();

private:
	sf::RenderWindow		mWindow{ sf::VideoMode{WINDOW_WIDTH, WINDOW_HEIGHT}, "BABY", sf::Style::Close };
	Player					player{};
	static const sf::Time	TimePerFrame;
	bool					_isRunning = false;

	Background				bg{ {WINDOW_WIDTH,WINDOW_HEIGHT} };
	Level _level{ "level0" };
	bool _levelEnd = false;

	std::vector<std::shared_ptr<Projectile>> bullets;
	std::vector<std::unique_ptr<Enemy>> _currentEnemies;

	bool shoot = false;

	void processEvents();
	void update(sf::Time delatTime);
	void render();

};