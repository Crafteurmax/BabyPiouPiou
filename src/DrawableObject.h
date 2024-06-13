#pragma once

#include <string>
#include <SFML/Graphics.hpp>

class DrawableObject {
public:
	DrawableObject() = default;
	virtual ~DrawableObject() = default;
	void draw() const;
	void setPosition(sf::Vector2f& pos);
	sf::Vector2f getPosition() const;
	virtual void update() = 0;

private:
	std::string _label;
	sf::Vector2f _position;
	sf::Vector2f _size;
	sf::Texture _texture;
};