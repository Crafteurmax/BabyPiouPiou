#include "SpellCard.h"

SpellCard::SpellCard(pugi::xml_node node) : _label(node.attribute("label").as_string()), _delay(node.attribute("delay").as_float())
{
	for (const auto& child : node.children()) {
		_projectiles.push_back(std::make_shared<Projectile>(child));
	}

}

//Générer les projectiles de la spellcards
float SpellCard::spawnSpell(std::vector<std::unique_ptr<Projectile>>& currentProjectiles, const sf::Vector2f& refPos) const
{
	for (const auto& proj : _projectiles) {
		auto projInstance = proj->clone();
		projInstance->reset(refPos);
		currentProjectiles.push_back(std::move(projInstance));
	}

	return _delay;
}
