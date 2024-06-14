#pragma once

#include <string>
#include <SFML/Graphics.hpp>

class DrawableObject {
public:
	DrawableObject(const sf::Vector2f& size, const std::string& label);
	virtual ~DrawableObject() = default;
	void draw(sf::RenderWindow& window) const;
	void setPosition(sf::Vector2f& pos);
	sf::Vector2f getPosition() const;
	virtual void update(const sf::Time& elapsedTime);

	sf::Vector2f getOffsetPosition();

protected:
	std::string _label;
	sf::Vector2f _position;
	sf::Vector2f _size;
	sf::Texture _texture;
	sf::Sprite _sprite;
};