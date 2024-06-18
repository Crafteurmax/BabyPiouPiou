#include "Game.h"
#include "SFML/Graphics.hpp"
#include <DrawableObject.h>


const sf::Time Game::TimePerFrame = sf::seconds(1.f / 60.f);


Game::Game()
{	// creation du message de gemeover
	font.loadFromFile("./resources/font/ARIAL.TTF");
	gameoverText = sf::Text("Gameover", font, 150.f);

	// on centre le message de gameover
	gameoverText.setOrigin(gameoverText.getGlobalBounds().getSize() / 2.f + gameoverText.getLocalBounds().getPosition());
	gameoverText.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
}

void Game::run()
{
	mWindow.setVerticalSyncEnabled(true);
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (mWindow.isOpen())
	{
		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;

			processEvents();
			if(_isRunning) update(TimePerFrame);
		}
		render();
	}
}


void Game::processEvents()
{
	sf::Event event{ sf::Event::Count }; // Initialization to an impossible value (in order to suppress Clang-Tidy warning)
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			processInputs(event.key.code, true);
			break;

		case sf::Event::KeyReleased:
			processInputs(event.key.code, false);
			break;

		case sf::Event::Closed:
			mWindow.close();
			break;

		default:
			// We simply ignore all other events
			break;
		}
	}
	
}

void Game::processInputs(const sf::Keyboard::Key& key, const bool& isPressed)
{
	player.handlePlayerInput(key, isPressed);
	bg.handlePlayerInput(key, isPressed);
	if (key == sf::Keyboard::Space) shoot = isPressed;
}

void Game::update(sf::Time deltaTime)
{
	if (_currentEnemies.empty()) {
		_levelEnd = _level.popWave(_currentEnemies);
	}

	playerUpdate(deltaTime);
	bg.update(deltaTime, player.getOffsetPosition(), { WINDOW_WIDTH, WINDOW_HEIGHT });
	enemiesUpdate(deltaTime);
	bulletsUpdate(deltaTime);

	tryShoot();
	
	purgeBullets();
	purgeEnemies();
}

void Game::playerUpdate(sf::Time deltaTime)
{
	// player update
	player.update(deltaTime, player.getOffsetPosition(), { WINDOW_WIDTH, WINDOW_HEIGHT });
	if (player.isDead()) _isRunning = false;
}

void Game::enemiesUpdate(sf::Time deltaTime)
{
	for (const auto& enemy : _currentEnemies) {
		enemy->update(deltaTime, player.getOffsetPosition(), { WINDOW_WIDTH, WINDOW_HEIGHT });
		enemy->trySpawnProjectiles(deltaTime, bullets);
	}
}

void Game::bulletsUpdate(sf::Time deltaTime)
{
	for (const auto& bullet : bullets)
	{
		bullet->update(deltaTime, player.getOffsetPosition(), { WINDOW_WIDTH, WINDOW_HEIGHT });
		if (player.takeHit(bullet->getOffsetPosition())) bullet->kill();
		if (bullet->getType() == ProjectileType::FROM_PLAYER) {
			for (const auto& enemy : _currentEnemies) {
				damageEnemy(*enemy, *bullet);
			}
				
		}
	}
}

void Game::damageEnemy(Enemy& enemy, Projectile& bullet) const {
	if (enemy.takeHit(bullet.getOffsetPosition())) bullet.kill();
}

void Game::tryShoot()
{
	if (shoot && player.getCooldown() <= 0) {
		bullets.push_back(std::make_shared<Projectile>(
			Projectile(2.f, ProjectileType::FROM_PLAYER,
				player.getOffsetPosition() + sf::Vector2f(-0.f, -1.f) * 50.f + sf::Vector2f(-16.f, 0.f), { 0.f,-400.f })));
		player.resetCooldown();
	}
}

void Game::purgeBullets()
{
	// purge bullets
	std::vector<std::shared_ptr<Projectile>> filteredBullets;
	std::ranges::copy_if(bullets.begin(), bullets.end(), std::back_inserter(filteredBullets),
		[](std::shared_ptr<Projectile> bullet) {return !bullet->isDead(); });
	bullets = filteredBullets;
}

void Game::purgeEnemies()
{
	// purge enemy
	for (int i = static_cast<int>(_currentEnemies.size()) - 1; i >= 0; i--) {
		if (_currentEnemies[i]->isDead()) _currentEnemies.erase(_currentEnemies.begin() + i);
	}
}

void Game::render()
{
	mWindow.clear();

	bg.draw(mWindow);
	player.draw(mWindow);
	for (const auto& bullet : bullets) bullet->draw(mWindow);
	for (const auto& enemy : _currentEnemies) enemy->draw(mWindow);
	if(!_isRunning) mWindow.draw(gameoverText);

	mWindow.display();
}