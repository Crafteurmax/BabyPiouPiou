#include "DrawableObject.h"
#include <iostream>

const std::string pathToSprite = "./resources/sprites/";

DrawableObject::DrawableObject(const std::string& label, const sf::Vector2f& size, const std::string& textureName, int repeat) : _label(label), _size(size)
{
	_texture = std::make_shared<sf::Texture>();
	//save texture as global because of this : https://www.sfml-dev.org/tutorials/2.6/graphics-sprite.php#the-white-square-problem
	if (!_texture->loadFromFile(pathToSprite + textureName))
	{
		// handle error
		std::cerr << "Texture not found : " << pathToSprite + textureName << std::endl;
	}
	_texture->setSmooth(true);
	_texture->setRepeated(true);
	if(repeat != 1) _sprite.setTextureRect(sf::IntRect(0, 0, static_cast<int>(size.x) * repeat, static_cast<int>(size.y) * repeat));
	_sprite.setTexture(*_texture);
	_sprite.setScale(size.x / static_cast<float>(_texture->getSize().x), size.y / static_cast<float>(_texture->getSize().y));
	_sprite.setPosition(_position);

}

DrawableObject::DrawableObject(const pugi::xml_node& node)
{

	const auto label = node.attribute("label").as_string();
	const auto pos = sf::Vector2f{ node.attribute("size_x").as_float(), node.attribute("size_y").as_float() };
	const auto sprite = node.attribute("sprite").as_string();

	*this = DrawableObject(label, pos, sprite, 1);
}

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

sf::Vector2f DrawableObject::getOffsetPosition() const {
	return { _position.x + _size.x/2,_position.y + _size.y/2 };
}
