
#include <random>
#include "SFML/Graphics.hpp"

class CoolMath {
public :
	static float Q_rsqrt(float number);
	static sf::Vector2f normalize(sf::Vector2f vect);
	static float norme(sf::Vector2f vect);
	static int randomInt(int const nbMax);
};