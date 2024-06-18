#include "SpellCard.h"

SpellCard::SpellCard(pugi::xml_node node) : _label(node.attribute("label").as_string()), _delay(node.attribute("delay").as_float())
{

	const std::weak_ptr<Projectile> projPref = std::make_shared<Projectile>(Projectile(1000.f, ProjectileType::FROM_PLAYER, { 200.f,200.f }, { 5.f,10.f }, { -2.f,0.f }));
	const std::string& label = "label";
	const auto pos = sf::Vector2f(0.f, 0.f);
	_projectilesRef.emplace_back(projPref, pos, label);

	for (const auto& child : node.children()) {
		//TODO WITCH PROJECTILE
	}

}

void SpellCard::spawnSpell(sf::Vector2f origin, std::vector<std::unique_ptr<Projectile>>& projectiles)
{
	for (const auto &projectile : _projectilesRef)
	{
		projectiles.push_back(projectile.spawn(origin));
	}
}

float SpellCard::getDelay()
{
	return _delay;
}
