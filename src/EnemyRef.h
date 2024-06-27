#ifndef ENEMY_REF
#define ENEMY_REF

#include "Enemy.h"

#include <optional>

//Contient des r�f�rences vers des enemis pr�ts � �tre instanci�s
class EnemyRef {
public:
	EnemyRef(const Enemy* & prefab, const sf::Vector2f& position, const std::string& label);
	std::unique_ptr<Enemy> spawn() const;
private:
	const Enemy* _enemyPrefab; //use lock !!!
	sf::Vector2f _position;
	std::string _label;
};




#endif