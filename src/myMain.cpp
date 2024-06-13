#include <iostream>
#include "myMain.h"

#include "Level.h"
#include "Game.h"

int myMain()
{
	std::cout << "Hello BabyPiouPiou!" << std::endl;
	Game game;
	game.run();

	//DEBUG VOHELI
	const auto level = Level("level0");
	
	return 0;
}
