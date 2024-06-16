#include "Game.h"
#include "SFML/Graphics.hpp"
#include <DrawableObject.h>

const sf::Time Game::TimePerFrame = sf::seconds(1.f / 60.f);


Game::Game()
{

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
			break;

		case sf::Event::KeyReleased:
			player.handlePlayerInput(event.key.code, false);
			bg.handlePlayerInput(event.key.code, false);
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
	player.update(deltaTime);
	bg.update(deltaTime);
}

void Game::render()
{
	mWindow.clear();
	bg.draw(mWindow);
	player.draw(mWindow);
	mWindow.display();
}