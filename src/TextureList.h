#ifndef TEXTURE_LIST
#define TEXTURE_LIST

#include <SFML/Graphics.hpp>

#include <map>
#include <string>

class TextureList {
public:
	static const std::shared_ptr<sf::Texture> getTexture(const std::string& textureName);
private:
	static std::map<std::string, std::weak_ptr<sf::Texture>, std::less<>> _textures;
};

#endif