#ifndef TEXTURE_LIST
#define TEXTURE_LIST

#include <SFML/Graphics.hpp>

#include <map>
#include <string>

//Singleton pour stocker une seule et unique fois les textures en mémoire
class TextureList {
public:
	static std::shared_ptr<sf::Texture> getTexture(const std::string& textureName);
private:
	//On utilise un weak_ptr, l'idée est de pouvoir laisser place ici à un cleanup de temps en temps pour libérer les textures chargées automatiquement lorsque non utilisées
	static std::map<std::string, std::weak_ptr<sf::Texture>, std::less<>> _textures;
};

#endif