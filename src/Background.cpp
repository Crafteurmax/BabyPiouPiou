#include "Background.h"


Background::Background(sf::Vector2f screenSize) :
    DrawableObject("sky", { SIZE,SIZE }, "sky.png", static_cast<int>(std::max(screenSize.x, screenSize.y) / SIZE)*3),
    midLayer( "sky2", { SIZE,SIZE }, "sky2.png" , static_cast<int>(std::max(screenSize.x, screenSize.y) / SIZE) * 3)
{  
}


void Background::update(const sf::Time& elapsedTime, sf::Vector2f playerPos, sf::Vector2f screenSize) {
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
    if (_position.x > 0) _position.x -= SIZE;
    if (_position.y > 0) _position.y -= SIZE;
    if (_position.x <= -SIZE) _position.x += SIZE;
    if (_position.y <= -SIZE) _position.y += SIZE;
    _sprite.setPosition(_position);

    sf::Vector2f _position2 = midLayer.getPosition();
    _position2 += movement * elapsedTime.asSeconds() * speed * 2.f;
    if (_position2.x > 0) _position2.x -= SIZE;
    if (_position2.y > 0) _position2.y -= SIZE;
    if (_position2.x <= -SIZE) _position2.x += SIZE;
    if (_position2.y <= -SIZE) _position2.y += SIZE;
    midLayer.setPosition(_position2);
    midLayer.update(elapsedTime, playerPos, screenSize);

}

void Background::handlePlayerInput(const sf::Keyboard::Key& key, const bool& isPressed) {
    if (key == sf::Keyboard::Z)
        isMoving[0] = isPressed;
    else if (key == sf::Keyboard::S)
        isMoving[1] = isPressed;
    else if (key == sf::Keyboard::Q)
        isMoving[2] = isPressed;
    else if (key == sf::Keyboard::D)
        isMoving[3] = isPressed;
}

void Background::draw(sf::RenderWindow& window) 
{
    window.draw(_sprite);
    midLayer.draw(window);
}