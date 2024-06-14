#ifndef ENEMY
#define ENEMY

#include "HpLiving.h"
#include "pugixml.hpp"

class Enemy : public HpLiving {
public :
	Enemy(pugi::xml_node& node);
	void update(const sf::Time& elapsedTime) override;
private:
	int _waveIndex;
};


#endif //ENEMY