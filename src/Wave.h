#ifndef WAVE
#define WAVE
#include "pugixml.hpp"

#include "EnemyRef.h"
#include "Enemy.h"

#include <vector>

class Wave {
public:
	Wave(const pugi::xml_node& node, const std::vector<std::shared_ptr<Enemy>>& enemiesObjects);
	void spawnEnemies(std::vector<std::unique_ptr<Enemy>>& enemies) const;

private:
	std::vector<EnemyRef> _enemiesRef;
};


#endif