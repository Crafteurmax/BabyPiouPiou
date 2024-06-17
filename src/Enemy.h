#ifndef ENEMY
#define ENEMY

#include "SpellCard.h"

#include "HpLiving.h"
#include "pugixml.hpp"

class Enemy : public HpLiving {
public :
	Enemy(const Enemy& other) = default;
	Enemy(const pugi::xml_node& node);
	Enemy(const Enemy& prefab, const std::string& label);

	inline std::unique_ptr<Enemy> clone() const { return std::make_unique<Enemy>(*this); }

	virtual void update(const sf::Time& elapsedTime, sf::Vector2f playerPos, sf::Vector2f screenSize);
	void setupInstance(const std::string& label, const sf::Vector2f& position);



private:
	int _waveIndex;
	std::vector<SpellCard> _spellcards;

protected:
	float speed = 10;
	float distance = 100;
};


#endif //ENEMY