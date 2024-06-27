#ifndef ENEMY_REF
#define ENEMY_REF

#include "Enemy.h"

#include <optional>

//Contient des références vers des enemis prêts à être instanciés
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