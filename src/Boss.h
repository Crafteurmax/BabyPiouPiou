#ifndef BOSS
#define BOSS

#include "Enemy.h"
#include "pugixml.hpp"

class Boss : public Enemy {

public:
	Boss(const Boss& other) = default;
	explicit Boss(const pugi::xml_node& node);

};


#endif