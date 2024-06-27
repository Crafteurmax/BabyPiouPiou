#ifndef SPELL_CARD
#define SPELL_CARD

#include <pugixml.hpp>
#include "Projectile.h"

#include <vector>

class SpellCard {
public:
	explicit SpellCard(pugi::xml_node node);
	float spawnSpell(std::vector<std::unique_ptr<Projectile>>& projectiles, const sf::Vector2f& refPos) const; //Renvoie le delay

private:
	std::vector<std::shared_ptr<Projectile>> _projectiles; //ON UTILISE UN SHARED_PTR CAR ICI, LA LISTE EST DUPLIQUEE LORS DE L'INSTANTIATION DES ENEMIS
	std::string _label;
	float _delay;
};


#endif // SPELL_CARD