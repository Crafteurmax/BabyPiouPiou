#include <gtest/gtest.h>
#include <Player.h>
#include "SFML/Graphics.hpp"

/*
C:\Users\Maxime_Sansane\Desktop\BabyPiouPiou\unitTests\resources\sprites\chat.png
													 ./resources/sprites/chat.png
*/

TEST(EmptyTest, UnitTest) {
	EXPECT_EQ(true, true);
}


TEST(PlayerMovement, test1) {
	Player player;
	player.setPosition({ 0.f, 0.f });
	EXPECT_EQ(player.getPosition().x, 0.f);
	EXPECT_EQ(player.getPosition().y, 0.f);
	sf::Time deltaTime = sf::Time(sf::microseconds(1));
	player.update(deltaTime, {0.f, 0.f}, {500.f, 500.f});
	EXPECT_EQ(player.getPosition().x, 0.f);
	EXPECT_EQ(player.getPosition().y, 0.f);
}

TEST(PlayerMovement, test2) {
	Player player;
	player.setPosition({ 250.f, 250.f });
	EXPECT_EQ(player.getPosition().x, 250.f);
	EXPECT_EQ(player.getPosition().y, 250.f);

	player.handlePlayerInput(sf::Keyboard::Z, true);
	sf::Time deltaTime = sf::Time(sf::microseconds(1000));
	player.update(deltaTime, {0.f, 0.f}, {500.f, 500.f});

	EXPECT_EQ(player.getPosition().x, 250.f);
	EXPECT_EQ(player.getPosition().y, 249.9f);

	player.handlePlayerInput(sf::Keyboard::Z, false);
	deltaTime = sf::Time(sf::microseconds(1));
	player.update(deltaTime, {0.f, 0.f}, {500.f, 500.f});

	EXPECT_EQ(player.getPosition().x, 250.f);
	EXPECT_EQ(player.getPosition().y, 249.9f);
}

TEST(PlayerMovement, test3) {
	Player player;
	sf::Vector2f vectorNull(0, 0);
	player.setPosition(vectorNull);
	EXPECT_EQ(player.getPosition().x, 0.f);
	EXPECT_EQ(player.getPosition().y, 0.f);

	player.handlePlayerInput(sf::Keyboard::S, true);
	sf::Time deltaTime = sf::Time(sf::microseconds(1000));
	player.update(deltaTime, {0.f, 0.f}, {500.f, 500.f});

	EXPECT_EQ(player.getPosition().x, 0.f);
	EXPECT_EQ(player.getPosition().y, 0.1f);

	player.handlePlayerInput(sf::Keyboard::S, false);
	deltaTime = sf::Time(sf::microseconds(1));
	player.update(deltaTime, {0.f, 0.f}, {500.f, 500.f});

	EXPECT_EQ(player.getPosition().x, 0.f);
	EXPECT_EQ(player.getPosition().y, 0.1f);
}

TEST(PlayerMovement, test4) {
	Player player;
	player.setPosition({ 250.f,250.f });
	EXPECT_EQ(player.getPosition().x, 250.f);
	EXPECT_EQ(player.getPosition().y, 250.f);

	player.handlePlayerInput(sf::Keyboard::Q, true);
	sf::Time deltaTime = sf::Time(sf::microseconds(1000));
	player.update(deltaTime, {0.f, 0.f}, {500.f, 500.f});

	EXPECT_EQ(player.getPosition().x, 249.9f);
	EXPECT_EQ(player.getPosition().y, 250.f);

	player.handlePlayerInput(sf::Keyboard::Q, false);
	deltaTime = sf::Time(sf::microseconds(1));
	player.update(deltaTime, {0.f, 0.f}, {500.f, 500.f});

	EXPECT_EQ(player.getPosition().x, 249.9f);
	EXPECT_EQ(player.getPosition().y, 250.f);
}

TEST(PlayerMovement, test5) {
	Player player;
	player.setPosition({ 0.f, 0.f });
	EXPECT_EQ(player.getPosition().x, 0.f);
	EXPECT_EQ(player.getPosition().y, 0.f);

	player.handlePlayerInput(sf::Keyboard::D, true);
	sf::Time deltaTime = sf::Time(sf::microseconds(1000));
	player.update(deltaTime, {0.f, 0.f}, {500.f, 500.f});

	EXPECT_EQ(player.getPosition().x, 0.1f);
	EXPECT_EQ(player.getPosition().y, 0.f);

	player.handlePlayerInput(sf::Keyboard::D, false);
	deltaTime = sf::Time(sf::microseconds(1));
	player.update(deltaTime, {0.f, 0.f}, {500.f, 500.f});

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