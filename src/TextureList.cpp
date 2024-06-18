#include "TextureList.h"

#include <iostream>

const std::string pathToSprite = "./resources/sprites/";
TextureList TextureList::_textureList;

TextureList::TextureList()
{
	_textureList = *this;
}

const std::shared_ptr<sf::Texture> TextureList::getTexture(const std::string& textureName)
{ //Dans le cas de multithread, il faudrait faire attention ici, mais c'est pas notre cas
	if (const auto textureIterator = _textureList._textures.find(textureName); textureIterator != _textureList._textures.end()) {
		return textureIterator->second.lock();
	}

	//NOT FOUND, LOAD THE TEXTURE

	const auto texture = std::make_shared<sf::Texture>();
	//save texture as global because of this : https://www.sfml-dev.org/tutorials/2.6/graphics-sprite.php#the-white-square-problem
	if (!texture->loadFromFile(pathToSprite + textureName))
	{
		// handle error
		std::cerr << "Texture not found : " << pathToSprite + textureName << std::endl;
	}
	texture->setSmooth(true);
	texture->setRepeated(true);

	_textureList._textures.try_emplace(textureName, static_cast<std::weak_ptr<sf::Texture>>(texture));

	return texture;
}
