#include "DrawableObject.h"
#include <iostream>

std::string pathToSprite = "./resources/sprites/";


DrawableObject::DrawableObject(const std::string& label, const sf::Vector2f& size, const std::string& textureName) : _label(label), _size(size)
{
	//_position = { 0,0 };
	//save texture as global because of this : https://www.sfml-dev.org/tutorials/2.6/graphics-sprite.php#the-white-square-problem
	if (!_texture.loadFromFile(pathToSprite + textureName))
	{
		// handle error
	}
	_texture.setSmooth(true);
	_sprite.setTexture(_texture);
	_sprite.setScale(size.x / _texture.getSize().x, size.y / _texture.getSize().y);
	_sprite.setPosition(_position);
}

DrawableObject::DrawableObject(const pugi::xml_node& node)
{

}

/*
DrawableObject::~DrawableObject()
{
	//TODO IMPLEMENT
}
*/

void DrawableObject::draw(sf::RenderWindow& window) const
{
	window.draw(_sprite);
}

void DrawableObject::setPosition(sf::Vector2f& pos)
{
	_position = pos;
}

sf::Vector2f DrawableObject::getPosition() const
{
	return _position;
}

void DrawableObject::update(const sf::Time& elapsedTime)
{
	//TODO IMPLEMENT
}

sf::Vector2f DrawableObject::getOffsetPosition() {
	return { _position.x - _size.x/2,_position.y - _size.y/2 };
}
