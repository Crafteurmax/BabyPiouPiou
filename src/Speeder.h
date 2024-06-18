#ifndef SPEEDER
#define SPEEDER

#include "Enemy.h"
#include "pugixml.hpp"

class Speeder : public Enemy {

public:
	Speeder(const Speeder& other) = default;
	explicit Speeder(const pugi::xml_node& node);


private:


};


#endif