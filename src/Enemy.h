#ifndef ENEMY
#define ENEMY

#include "SpellCard.h"

#include "HpLiving.h"
#include "pugixml.hpp"

class Enemy : public HpLiving {
public :
	Enemy(const pugi::xml_node& node);
	void update(const sf::Time& elapsedTime) override;
private:
	int _waveIndex;
	std::vector<SpellCard> _spellcards;
};


#endif //ENEMY