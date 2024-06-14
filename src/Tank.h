#ifndef TANK
#define TANK

#include "Enemy.h"
#include "pugixml.hpp"

class Tank : public Enemy {

public:
	explicit Tank(pugi::xml_node& node);
	void update() override;
private:


};


#endif