#include "DrawableObject.h"
#include <iostream>

std::string pathToSprite = "./resources/sprites/";

DrawableObject::DrawableObject(const std::string& label, const sf::Vector2f& size, const std::string& textureName, int repeat) : _label(label), _size(size)
{
	//save texture as global because of this : https://www.sfml-dev.org/tutorials/2.6/graphics-sprite.php#the-white-square-problem
	if (!_texture.loadFromFile(pathToSprite + textureName))
	{
		// handle error
	}
	_texture.setSmooth(true);
	_texture.setRepeated(true);
	if(repeat != 1) _sprite.setTextureRect(sf::IntRect(0, 0, size.x * repeat, size.y * repeat));
	_sprite.setTexture(_texture);
	_sprite.setScale(size.x / _texture.getSize().x, size.y / _texture.getSize().y);
	_sprite.setPosition(_position);
}

DrawableObject::DrawableObject(const pugi::xml_node& node)
{

}

DrawableObject::DrawableObject(const DrawableObject & prefab, std::string label)
{
	_label = label;
}
/*
DrawableObject::~DrawableObject()
{
	//TODO IMPLEMENT
}
*/

void DrawableObject::draw(sf::RenderWindow& window)
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
	_sprite.setPosition(_position);
}

sf::Vector2f DrawableObject::getOffsetPosition() {
	return { _position.x - _size.x/2,_position.y - _size.y/2 };
}
