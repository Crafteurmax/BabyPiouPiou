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
	explicit Projectile(const Projectile& other) = default;


	explicit Projectile(const pugi::xml_node& node);
	Projectile(float _lifetime, ProjectileType _projectileType, sf::Vector2f pos, sf::Vector2f vit, 
		sf::Vector2f acc = { 0.f,0.f }, sf::Vector2f aco = { 0.f,0.f });
	void update(const sf::Time& elapsedTime, sf::Vector2f playerPos, sf::Vector2f screenSize) override;
	void reset(const sf::Vector2f& refPos);
	void kill();
	ProjectileType getType() const;

	bool isDead() const;

	std::unique_ptr<Projectile> clone() { return std::make_unique<Projectile>(*this);  };

private:
	ProjectileType _projectileType;
	float _currentLifetime;
	sf::Vector2f currentVit;
	sf::Vector2f currentAcc;
	sf::Vector2f currentAco;
	sf::Vector2f deltaPos;
};

#endif //PROJECTILE