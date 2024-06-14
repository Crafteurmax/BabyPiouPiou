#ifndef LEVEL
#define LEVEL

#include <string>
#include <pugixml.hpp>
#include <vector>
#include "Enemy.h"

class Level {
public:
	explicit Level(const std::string& name);
private:
	std::string _label;
	std::vector<std::unique_ptr<Enemy>> _enemiesList;
	void loadPrefabs(const pugi::xml_node& prefabsNode);
	void loadObjects(const pugi::xml_node& prefabsNode);
};

#endif // LEVEL