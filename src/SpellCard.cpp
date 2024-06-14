#include "SpellCard.h"

SpellCard::SpellCard(pugi::xml_node node) : _label(node.attribute("label").as_string()), _delay(node.attribute("delay").as_float())
{
	for (const auto& child : node.children()) {
		//TODO WITCH PROJECTILE
	}

}
