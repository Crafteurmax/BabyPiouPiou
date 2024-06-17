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

	inline std::unique_ptr<Enemy> clone() const { return std::make_unique<Enemy>(*this); }

	virtual void update2(const sf::Time& elapsedTime, sf::Vector2f playerPos, sf::Vector2f screenSize);
	void setupInstance(const std::string& label, const sf::Vector2f& position);
	std::vector<std::unique_ptr<Projectile>> shoot(const sf::Time& elapsedTime, sf::Vector2f playerPos);


protected:


	float speed = 10;
	float distance = 100;

private:
	std::vector<SpellCard> _spellcards;
	std::vector<float> _spellCoolDown;


};


#endif //ENEMY