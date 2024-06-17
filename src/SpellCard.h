#ifndef SPELL_CARD
#define SPELL_CARD

#include <pugixml.hpp>
#include "Projectile.h"

#include <vector>

class SpellCard {
public:
	explicit SpellCard(pugi::xml_node node);
	std::vector<std::unique_ptr<Projectile>> spawnSpell();
	float getDelay();

private:
	std::vector<Projectile> _projectiles;
	std::string _label;
	float _delay;
};


#endif // SPELL_CARD