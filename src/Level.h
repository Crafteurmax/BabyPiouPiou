#ifndef LEVEL
#define LEVEL

#include <string>
#include <pugixml.hpp>
#include <vector>
#include "Enemy.h"
#include "Wave.h"
#include "Drunk.h"

class Level {
public:
	explicit Level(const std::string& name);
	bool popWave(std::vector<std::unique_ptr<Enemy>>& enemies); //return false is level ends, no wave left
private:
	std::string _label;
	std::vector<std::shared_ptr<Enemy>> _enemiesList;
	std::vector<Wave> _waves;
	std::vector<Wave>::iterator _currentWave;

	void loadPrefabs(const pugi::xml_node& prefabsNode);
	void loadObjects(const pugi::xml_node& prefabsNode);
};

#endif // LEVEL