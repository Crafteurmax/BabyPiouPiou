#ifndef TANK
#define TANK

#include "Enemy.h"
#include "pugixml.hpp"

class Tank : public Enemy {

public:
	Tank(const Tank& other) = default;
	explicit Tank(const pugi::xml_node& node);


private:


};


#endif