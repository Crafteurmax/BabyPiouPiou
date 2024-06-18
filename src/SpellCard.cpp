#include "SpellCard.h"

SpellCard::SpellCard(pugi::xml_node node) : _label(node.attribute("label").as_string()), _delay(node.attribute("delay").as_float())
{
	for (const auto& child : node.children()) {
		_projectiles.push_back(std::make_shared<Projectile>(child)); //TODO CHECK HERITAGE
	}

}

std::vector<std::shared_ptr<Projectile>> SpellCard::spawnSpell()
{
	return std::vector<std::shared_ptr<Projectile>>();
}

float SpellCard::getDelay()
{
	return _delay;
}
