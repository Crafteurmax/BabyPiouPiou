#include "SpellCard.h"

SpellCard::SpellCard(pugi::xml_node node) : _label(node.attribute("label").as_string()), _delay(node.attribute("delay").as_float())
{
	for (const auto& child : node.children()) {
		_projectiles.push_back(std::make_shared<Projectile>(child)); //TODO CHECK HERITAGE
	}

}

float SpellCard::spawnSpell(std::vector<std::shared_ptr<Projectile>>& currentProjectiles, const sf::Vector2f& refPos)
{
	for (const auto proj : _projectiles) {
		auto projInstance = proj->clone();
		projInstance->reset(refPos);
		currentProjectiles.push_back(std::move(projInstance));
	}

	return _delay;
}

float SpellCard::getDelay() const
{
	return _delay;
}
