#include "SpellCard.h"

SpellCard::SpellCard(pugi::xml_node node) : _label(node.attribute("label").as_string()), _delay(node.attribute("delay").as_float())
{
	for (const auto& child : node.children()) {
		//TODO WITCH PROJECTILE
	}

}

std::vector<std::unique_ptr<Projectile>> SpellCard::spawnSpell()
{
	return std::vector<std::unique_ptr<Projectile>>();
}

float SpellCard::getDelay()
{
	return _delay;
}
