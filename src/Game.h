#ifndef GAME
#define GAME

#include "SFML/Graphics.hpp"
#include "Player.h"
#include "Background.h"
#include "Projectile.h"
#include "Enemy.h"
#include "Level.h"


constexpr int WINDOW_WIDTH = 1900;
constexpr int WINDOW_HEIGHT = 1000;


class Game {
public :
	Game();
	void run();

private:
	sf::RenderWindow		mWindow{ sf::VideoMode{WINDOW_WIDTH, WINDOW_HEIGHT}, "BABY", sf::Style::Close };
	Player					player{};
	static const sf::Time	TimePerFrame;
	bool					_isRunning = true;

	Background				bg{ {WINDOW_WIDTH,WINDOW_HEIGHT} };
	Level _level{ "level0" };
	bool _levelEnd = false;

	std::vector<std::shared_ptr<Projectile>> bullets;
	std::vector<std::unique_ptr<Enemy>> _currentEnemies;

	bool shoot = false;

	sf::Font font;
	sf::Text gameoverText;

	void processEvents();
	void processInputs(const sf::Keyboard::Key& key, const bool& isPressed);

	void update(sf::Time deltaTime);
	void playerUpdate(sf::Time deltaTime);
	void enemiesUpdate(sf::Time deltaTime);
	void bulletsUpdate(sf::Time deltaTime);

	void tryShoot();

	void purgeBullets();
	void purgeEnemies();

	void render();
	void damageEnemy(Enemy& enemy, Projectile& bullet) const;

};

#endif