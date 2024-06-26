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

	for (const auto& child : level.children()) {
		std::cout << "Child found : " << child.name() << std::endl;
		if (child.name() == std::string("Prefabs")) {
			std::cout << "loadPrefabs" << std::endl;
			loadPrefabs(child);
		}

		if (child.name() == std::string("Waves")) {
			std::cout << "loadObjects" << std::endl;
			loadObjects(child);
		}
	}

	_currentWave = _waves.begin();
}

void Level::loadPrefabs(const pugi::xml_node& prefabsNode)
{
	for (const auto& child : prefabsNode.children()) {
		const std::string enemy_type = child.name();

		//G�rer en fonction du type d'enemi
		if (enemy_type == "Drunk") {
			_enemiesList.push_back(std::make_unique<Drunk>(child));
		}
		else if (enemy_type == "Tank") {
			_enemiesList.push_back(std::make_unique<Tank>(child));
		}
		else if (enemy_type == "Speeder") {
			_enemiesList.push_back(std::make_unique<Speeder>(child));
		}
		else if (enemy_type == "Boss") {
			_enemiesList.push_back(std::make_unique<Boss>(child));
		}
		else {
			_enemiesList.push_back(std::make_unique<Enemy>(child));
		}

	}
}

void Level::loadObjects(const pugi::xml_node& wavesNodes)
{
	
	for (const auto& child : wavesNodes.children()) {
		_waves.emplace_back(child, _enemiesList);
	}
}


bool Level::popWave(std::vector<std::unique_ptr<Enemy>>& enemies) {
	if (_currentWave >= _waves.end()) {
		return false;
	}

	const auto& wave = *_currentWave;
	wave.spawnEnemies(enemies);

	_currentWave++;
	return true;
}