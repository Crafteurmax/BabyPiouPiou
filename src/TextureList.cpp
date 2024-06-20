#include "TextureList.h"

#include <iostream>

const std::string pathToSprite = "./resources/sprites/";

std::map<std::string, std::weak_ptr<sf::Texture>, std::less<>> TextureList::_textures;

std::shared_ptr<sf::Texture> TextureList::getTexture(const std::string& textureName)
{ 

	//Dans le cas de multithread, il faudrait faire attention ici, mais c'est pas notre cas
	if (const auto textureIterator = _textures.find(textureName); textureIterator != _textures.end()) {
		//--- Modifié avant la présentation
		if (const auto& sharedPtr = textureIterator->second.lock()) {
			
			return sharedPtr;
		}
		_textures.erase(textureIterator);
		//-- Modifié avant la présentation -- ANCIEN CODE
		//return textureIterator->second.lock();

		std::cout << "(Re)loading : " << textureName << std::endl;
	}

	std::cout << "Loading : " << textureName << std::endl;
	
	//NOT FOUND, LOAD THE TEXTURE

	const auto texture = std::make_shared<sf::Texture>();
	//save texture as global because of this : https://www.sfml-dev.org/tutorials/2.6/graphics-sprite.php#the-white-square-problem
	if (!texture->loadFromFile(pathToSprite + textureName))
	{
		// handle error
		std::cerr << "Texture not found : " << pathToSprite + textureName << std::endl;
		return std::shared_ptr<sf::Texture>();
	}
	texture->setRepeated(true);

	_textures.try_emplace(textureName, static_cast<std::weak_ptr<sf::Texture>>(texture));

	return texture;
}
