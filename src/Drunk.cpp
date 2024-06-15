#include "Drunk.h"
#include "pugixml.hpp"

/*
<Tank label = "test_enemy" size_x = "100" size_y = "100" sprite = "chat.png">
	<Spellcard label = "spell_1" delay = "5">
		<ProjectileA label = "projectile_1" lifetime = "5.0" vel_x = "10" vel_y = "10" delta_x = "0" delta_y = "0" size_x = "10" sprite = "chat.png" / >
	< / Spellcard>
< / Tank>
*/
Drunk::Drunk(pugi::xml_node& refNode) :
	Enemy(refNode)
{

}

Drunk::Drunk(const Drunk& prefabDrunk, sf::Vector2f pos, float startAngle, std::string label) :
	Enemy(prefabDrunk, label)
{
	movingCenter = pos;
	currentAngle = startAngle;
}

void Drunk::update(const sf::Time& elapsedTime)
{
	currentAngle += angularVelocity * elapsedTime.asSeconds();

	_position = movingCenter + sf::Vector2f(cos(currentAngle), sin(currentAngle))*radius;
}
