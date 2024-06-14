#include "Level.h"

#include <iostream>

Level::Level(const std::string& name) {
	//Get Level XML Path
	const auto path = "./resources/levels/" + name + ".xml";
	pugi::xml_document levelXml;
	const auto result = levelXml.load_file(path.c_str());
	if (result.status != pugi::status_ok) {
		std::cerr << "Can't load file : " << path << " with error : " << result.status << std::endl;
	}

	auto level = levelXml.first_child();

	if (level == nullptr) {
		std::cerr << "Empty Level : " << path << " with error : " << result.status << std::endl;
	}

	_label = level.attribute("label").as_string();

	/*loadPrefabs(level.find_child("Prefabs"));
	loadPrefabs(level.find_child("Waves"));*/
}

void Level::loadPrefabs(const pugi::xml_node& prefabsNode)
{
	//for (const auto& child : prefabsNode.children()) {
	//	//TODO Implement multi enemy types
	//	const auto enemyPrefab = Enemy(child);
	//}
}

void Level::loadObjects(const pugi::xml_node& prefabsNode)
{

}
