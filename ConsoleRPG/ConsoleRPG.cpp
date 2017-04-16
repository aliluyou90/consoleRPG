// ConsoleRPG.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#include <iostream>
#include "Game.h"
using namespace std;

int main()
{
	srand(time(NULL));
	Game game;
	game.initGame();
	//Inventory inv;

	while (game.getPlaying()) {

		game.mainMenu();

	}


    return 0;
}

