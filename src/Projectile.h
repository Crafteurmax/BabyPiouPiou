#ifndef PROJECTILE
#define PROJECTILE

#include "DrawableObject.h"

enum class ProjectileType {
	NO_DAMAGE = 0,
	FROM_PLAYER = 1,
	FROM_ENEMY = 2
};

class Projectile : public DrawableObject {
public:
	Projectile(const pugi::xml_node& node);
	void update(const sf::Time& elapsedTime) override = 0;

private:
	float _lifetime;
	ProjectileType _projectileType;
};

#endif //PROJECTILE