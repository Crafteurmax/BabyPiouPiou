#include "Level.h"

#include <iostream>

Level::Level(const std::string& label) {
	//Get Level XML Path
	const auto path = "./resources/levels/" + label + ".xml";
	pugi::xml_document levelXml;
	const auto result = levelXml.load_file(path.c_str());
	if (result.status != pugi::status_ok) {
		std::cerr << "Can't load file : " << path << " with error : " << result.status << std::endl;
	}

}