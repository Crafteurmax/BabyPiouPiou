#include <gtest/gtest.h>
#include <Player.h>
#include "SFML/Graphics.hpp"


TEST(EmptyTest, UnitTest) {
	EXPECT_EQ(true, true);
}


TEST(PlayerMovement, test1) {
	Player player;
	sf::Vector2f vectorNull(0, 0);
	player.setPosition(vectorNull);
	EXPECT_EQ(player.getPosition().x, 0.f);
	EXPECT_EQ(player.getPosition().y, 0.f);
	sf::Time deltaTime = sf::Time(sf::microseconds(1));
	player.update(deltaTime);
	EXPECT_EQ(player.getPosition().x, 0.f);
	EXPECT_EQ(player.getPosition().y, 0.f);
}

TEST(PlayerMovement, test2) {
	Player player;
	sf::Vector2f vectorNull(0, 0);
	player.setPosition(vectorNull);
	EXPECT_EQ(player.getPosition().x, 0.f);
	EXPECT_EQ(player.getPosition().y, 0.f);

	player.handlePlayerInput(sf::Keyboard::Z, true);
	sf::Time deltaTime = sf::Time(sf::microseconds(1000));
	player.update(deltaTime);

	EXPECT_EQ(player.getPosition().x, 0.f);
	EXPECT_EQ(player.getPosition().y, -0.1f);

	player.handlePlayerInput(sf::Keyboard::Z, false);
	deltaTime = sf::Time(sf::microseconds(1));
	player.update(deltaTime);

	EXPECT_EQ(player.getPosition().x, 0.f);
	EXPECT_EQ(player.getPosition().y, -0.1f);
}

TEST(PlayerMovement, test3) {
	Player player;
	sf::Vector2f vectorNull(0, 0);
	player.setPosition(vectorNull);
	EXPECT_EQ(player.getPosition().x, 0.f);
	EXPECT_EQ(player.getPosition().y, 0.f);

	player.handlePlayerInput(sf::Keyboard::S, true);
	sf::Time deltaTime = sf::Time(sf::microseconds(1000));
	player.update(deltaTime);

	EXPECT_EQ(player.getPosition().x, 0.f);
	EXPECT_EQ(player.getPosition().y, 0.1f);

	player.handlePlayerInput(sf::Keyboard::S, false);
	deltaTime = sf::Time(sf::microseconds(1));
	player.update(deltaTime);

	EXPECT_EQ(player.getPosition().x, 0.f);
	EXPECT_EQ(player.getPosition().y, 0.1f);
}

TEST(PlayerMovement, test4) {
	Player player;
	sf::Vector2f vectorNull(0, 0);
	player.setPosition(vectorNull);
	EXPECT_EQ(player.getPosition().x, 0.f);
	EXPECT_EQ(player.getPosition().y, 0.f);

	player.handlePlayerInput(sf::Keyboard::Q, true);
	sf::Time deltaTime = sf::Time(sf::microseconds(1000));
	player.update(deltaTime);

	EXPECT_EQ(player.getPosition().x, -0.1f);
	EXPECT_EQ(player.getPosition().y, 0.f);

	player.handlePlayerInput(sf::Keyboard::Q, false);
	deltaTime = sf::Time(sf::microseconds(1));
	player.update(deltaTime);

	EXPECT_EQ(player.getPosition().x, -0.1f);
	EXPECT_EQ(player.getPosition().y, 0.f);
}

TEST(PlayerMovement, test5) {
	Player player;
	sf::Vector2f vectorNull(0, 0);
	player.setPosition(vectorNull);
	EXPECT_EQ(player.getPosition().x, 0.f);
	EXPECT_EQ(player.getPosition().y, 0.f);

	player.handlePlayerInput(sf::Keyboard::D, true);
	sf::Time deltaTime = sf::Time(sf::microseconds(1000));
	player.update(deltaTime);

	EXPECT_EQ(player.getPosition().x, 0.1f);
	EXPECT_EQ(player.getPosition().y, 0.f);

	player.handlePlayerInput(sf::Keyboard::D, false);
	deltaTime = sf::Time(sf::microseconds(1));
	player.update(deltaTime);

	EXPECT_EQ(player.getPosition().x, 0.1f);
	EXPECT_EQ(player.getPosition().y, 0.f);
}

TEST(HealthSystem, test1) {
	HpLiving hp("test",{100, 100}, 10, "chat.png");
	ASSERT_FALSE(hp.isDead());
	ASSERT_EQ(hp.getHealth(), 10);
	hp.damage(5);
	ASSERT_EQ(hp.getHealth(), 5);
	hp.damage(5);
	ASSERT_EQ(hp.getHealth(), 0);
	ASSERT_TRUE(hp.isDead());

}