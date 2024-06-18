#ifndef ENEMY
#define ENEMY

#include "SpellCard.h"

#include "HpLiving.h"
#include "pugixml.hpp"
#include "CoolMath.h"

class Enemy : public HpLiving {
public :
	Enemy(const Enemy& other) = default;
	explicit Enemy(const pugi::xml_node& node);

	virtual inline std::unique_ptr<Enemy> clone() const { return std::make_unique<Enemy>(*this); }

	void update(const sf::Time& elapsedTime, sf::Vector2f playerPos, sf::Vector2f screenSize) override;
	virtual void setupInstance(const std::string& label, const sf::Vector2f& position);
	void trySpawnProjectiles(const sf::Time& elapsedTime, std::vector<std::shared_ptr<Projectile>>& projectiles);


protected: //A éviter :'(
	float speed;
	float distance;

private:
	std::vector<SpellCard> _spellcards;
	float _currentSpellTime = 0.0f;


};


#endif //ENEMY