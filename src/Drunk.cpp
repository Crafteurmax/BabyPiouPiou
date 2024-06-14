#include "Drunk.h"

void Drunk::update(const sf::Time& elapsedTime)
{
	currentAngle += angularVelocity * elapsedTime.asSeconds();
}
