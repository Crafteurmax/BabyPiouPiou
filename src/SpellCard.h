#ifndef SPELL_CARD
#define SPELL_CARD

#include <pugixml.hpp>
#include "Projectile.h"

#include <vector>

class SpellCard {
public:
	SpellCard(pugi::xml_node node);

private:
	std::vector<Projectile> _projectiles;
	std::string _label;
	float _delay;
};


#endif // SPELL_CARD