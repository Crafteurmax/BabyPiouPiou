#ifndef BULLET_REF
#define BULLET_REF

#include "Enemy.h"

#include <optional>

class BulletRef {
public:
	BulletRef(const std::weak_ptr<Projectile>& prefab, const sf::Vector2f& position, const std::string& label);
	std::unique_ptr<Projectile> spawn(sf::Vector2f origin) const;
private:
	//Voir s'il vaut mieux ne pas mettre des observeurs
	std::weak_ptr<Projectile> _BulletPrefab; //use lock !!!
	sf::Vector2f _position;
	std::string _label;
};




#endif