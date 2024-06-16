#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include "pugixml.hpp"

class DrawableObject {
public:
	DrawableObject(const DrawableObject& other) = default;

	DrawableObject(const pugi::xml_node& node);
	DrawableObject(const std::string& label, const sf::Vector2f& size, const std::string& textureName, int repeat = 1);
	DrawableObject(const DrawableObject& prefab, std::string label);
	virtual ~DrawableObject() = default;
	virtual void draw(sf::RenderWindow& window);
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