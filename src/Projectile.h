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
	void update() override = 0;

private:
	float _lifetime;
	ProjectileType _projectileType;
};

#endif //PROJECTILE