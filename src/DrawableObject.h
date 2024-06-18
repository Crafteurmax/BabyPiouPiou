#ifndef DRAWABLE_OBJECT
#define DRAWABLE_OBJECT

#include <string>
#include <SFML/Graphics.hpp>
#include "pugixml.hpp"

#include <iostream>

class DrawableObject {
public:
	DrawableObject(const DrawableObject& other) = default;

	explicit DrawableObject(const pugi::xml_node& node);
	DrawableObject(const std::string& label, const sf::Vector2f& size, const std::string& textureName
		, const sf::Vector2f pos = {0.f,0.f}, int repeat = 1);
	virtual ~DrawableObject() = default;
	virtual void draw(sf::RenderWindow& window);
	void setPosition(const sf::Vector2f& pos);
	sf::Vector2f getPosition() const;
	virtual void update(const sf::Time& elapsedTime, sf::Vector2f playerPos, sf::Vector2f screenSize);

	void setLabel(std::string_view label) { _label = label; }
	std::string getLabel() const { return _label; }

	sf::Vector2f getOffsetPosition() const;


private:
	std::string _label;
	std::shared_ptr<sf::Texture> _texture;
protected: //A éviter la prochaine fois

	sf::Vector2f _position;
	sf::Vector2f _size;
	sf::Sprite _sprite;
};


#endif