#include "Game.h"
#include "SFML/Graphics.hpp"
#include <DrawableObject.h>

const sf::Time Game::TimePerFrame = sf::seconds(1.f / 60.f);


Game::Game() 
{
	bullets.push_back(std::make_unique<Projectile>(Projectile(1000.f, ProjectileType::FROM_PLAYER, { 200.f,200.f }, { 5.f,10.f },{-2.f,0.f})));
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
			update(TimePerFrame);
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
			player.handlePlayerInput(event.key.code, true);
			bg.handlePlayerInput(event.key.code, true);
			if (event.key.code == sf::Keyboard::Space) shoot = true;
			break;

		case sf::Event::KeyReleased:
			player.handlePlayerInput(event.key.code, false);
			bg.handlePlayerInput(event.key.code, false);
			if (event.key.code == sf::Keyboard::Space) shoot = false;
			break;

		case sf::Event::MouseButtonReleased:
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

void Game::update(sf::Time deltaTime)
{
	if (_currentEnemies.empty()) {
		_levelEnd = _level.popWave(_currentEnemies);
	}

	player.update(deltaTime, player.getOffsetPosition(), { WINDOW_WIDTH, WINDOW_HEIGHT });
	bg.update(deltaTime, player.getOffsetPosition(), { WINDOW_WIDTH, WINDOW_HEIGHT });
	for (const auto& enemy : _currentEnemies) enemy->update(deltaTime,player.getOffsetPosition(), { WINDOW_WIDTH, WINDOW_HEIGHT});
	for (const auto& bullet : bullets)
	{
		bullet->update(deltaTime, player.getOffsetPosition(), { WINDOW_WIDTH, WINDOW_HEIGHT });
		if(player.takeHit(bullet->getOffsetPosition())) bullet->kill();
	}


	if (shoot && player.getCooldown() <= 0) {
		bullets.push_back(std::make_shared<Projectile>(
			Projectile(2.f, ProjectileType::FROM_PLAYER,
				player.getOffsetPosition() + sf::Vector2f(-0.f, -1.f) * 50.f + sf::Vector2f(-16.f, 0.f), { 0.f,-400.f })));
		player.resetCooldown();
	}

	std::vector<std::shared_ptr<Projectile>> filteredBullets;
	std::copy_if(bullets.begin(), bullets.end(), std::back_inserter(filteredBullets),
		[](std::shared_ptr<Projectile> bullet) {return !bullet->isDead(); });
	bullets = filteredBullets;
}

void Game::render()
{
	mWindow.clear();
	bg.draw(mWindow);
	player.draw(mWindow);
	for (const auto& bullet : bullets) bullet->draw(mWindow);
	for (const auto& enemy : _currentEnemies) enemy->draw(mWindow);

	mWindow.display();
}