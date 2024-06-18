#include "DrawableObject.h"
#include <iostream>

#include "TextureList.h"

DrawableObject::DrawableObject(const std::string& label, const sf::Vector2f& size, const std::string& textureName,
	const sf::Vector2f pos, int repeat) : _label(label), _size(size)
{
	_position = pos;
	_texture = TextureList::getTexture(textureName);
	if(repeat != 1) _sprite.setTextureRect(sf::IntRect(0, 0, static_cast<int>(size.x) * repeat, static_cast<int>(size.y) * repeat));
	_sprite.setTexture(*_texture);
	_sprite.setScale(size.x / static_cast<float>(_texture->getSize().x), size.y / static_cast<float>(_texture->getSize().y));
	_sprite.setPosition(_position);

}

DrawableObject::DrawableObject(const pugi::xml_node& node)
{

	const auto label = node.attribute("label").as_string();
	const auto size = sf::Vector2f{ node.attribute("size_x").as_float(), node.attribute("size_y").as_float() };
	const auto sprite = node.attribute("sprite").as_string();

	*this = DrawableObject(label, size, sprite);
}

void DrawableObject::draw(sf::RenderWindow& window)
{
	window.draw(_sprite);
}

void DrawableObject::setPosition(const sf::Vector2f& pos)
{
	_position = pos;
	_sprite.setPosition(pos);
}

sf::Vector2f DrawableObject::getPosition() const
{
	return _position;
}

void DrawableObject::update(const sf::Time& elapsedTime, sf::Vector2f playerPos, sf::Vector2f screenSize)
{
	_sprite.setPosition(_position);
}

sf::Vector2f DrawableObject::getOffsetPosition() const {
	return { _position.x + _size.x/2.f,_position.y + _size.y/2.f };
}
