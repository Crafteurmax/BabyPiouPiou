#ifndef TANK
#define TANK

#include "Enemy.h"
#include "pugixml.hpp"

class Tank : public Enemy {

public:
	Tank(const Tank& other) = default;

	explicit Tank(pugi::xml_node& node);
	void update(const sf::Time& elapsedTime) override;
private:


};


#endif