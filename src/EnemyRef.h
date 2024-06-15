#ifndef ENEMY_REF
#define ENEMY_REF

#include "Enemy.h"

#include <optional>

class EnemyRef {
public:
	EnemyRef(const std::weak_ptr<Enemy>& prefab, const sf::Vector2f& position, const std::string& label);
	std::unique_ptr<Enemy> spawn() const;
private:
	//Voir s'il vaut mieux ne pas mettre des observeurs
	std::weak_ptr<Enemy> _enemyPrefab; //use lock !!!
	sf::Vector2f _position;
	std::string _label;
};




#endif