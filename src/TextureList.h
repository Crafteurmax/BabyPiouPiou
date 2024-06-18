#ifndef TEXTURE_LIST
#define TEXTURE_LIST

#include <SFML/Graphics.hpp>

#include <map>
#include <string>

//Singleton pour stocker une seule et unique fois les textures en m�moire
class TextureList {
public:
	static std::shared_ptr<sf::Texture> getTexture(const std::string& textureName);
private:
	//On utilise un weak_ptr, l'id�e est de pouvoir laisser place ici � un cleanup de temps en temps pour lib�rer les textures charg�es automatiquement lorsque non utilis�es
	static std::map<std::string, std::weak_ptr<sf::Texture>, std::less<>> _textures;
};

#endif