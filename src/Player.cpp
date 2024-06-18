#include "Player.h"

Player::Player() :
    HpLiving("player", { 100, 100 }, 10, "chat.png")
{

}

void Player::update(const sf::Time& elapsedTime, sf::Vector2f playerPos, sf::Vector2f screenSize) {
    normalShootCooldown -= elapsedTime.asSeconds();
    sf::Vector2f movement(0.f, 0.f);
    if (isMoving[0])
        movement.y -= 1;
    if (isMoving[1])
        movement.y += 1;
    if (isMoving[2])
        movement.x -= 1;
    if (isMoving[3])
        movement.x += 1;
    
    if (movement.x != 0 && movement.y != 0) movement *= invSqr2;
    
    _position += movement * elapsedTime.asSeconds() * speed;
    _sprite.setPosition(_position);
}

void Player::handlePlayerInput(const sf::Keyboard::Key& key, const bool& isPressed) {
    if (key == sf::Keyboard::Z)
        isMoving[0] = isPressed;
    else if (key == sf::Keyboard::S)
        isMoving[1] = isPressed;
    else if (key == sf::Keyboard::Q)
        isMoving[2] = isPressed;
    else if (key == sf::Keyboard::D)
        isMoving[3] = isPressed;
}

float Player::getCooldown() const
{
    return normalShootCooldown;
}

void Player::resetCooldown()
{
    normalShootCooldown = 0.2f;
}

bool Player::takeHit(sf::Vector2f bulletPos)
{
    sf::Vector2f direction = getOffsetPosition() - bulletPos;
    float norme = CoolMath::norme(direction);

    if (norme > hitBoxSize) return false;
    damage(10);
    return true;
}
