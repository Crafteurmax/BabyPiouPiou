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
	Projectile(float _lifetime, ProjectileType _projectileType, sf::Vector2f pos, sf::Vector2f vit, 
		sf::Vector2f acc = { 0.f,0.f }, sf::Vector2f aco = { 0.f,0.f });
	void update(const sf::Time& elapsedTime) override;

private:
	float _lifetime;
	ProjectileType _projectileType;

	sf::Vector2f vit;
	sf::Vector2f acc;
	sf::Vector2f aco;
};

#endif //PROJECTILE