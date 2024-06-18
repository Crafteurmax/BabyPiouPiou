#ifndef SPELL_CARD
#define SPELL_CARD

#include <pugixml.hpp>
#include "Projectile.h"

#include <vector>
#include <BulletRef.h>

class SpellCard {
public:
	explicit SpellCard(pugi::xml_node node);
	void spawnSpell(sf::Vector2f origin, std::vector<std::unique_ptr<Projectile>>& projectiles);
	float getDelay();

private:
	std::vector<BulletRef> _projectilesRef;
	std::string _label;
	float _delay;
};


#endif // SPELL_CARD