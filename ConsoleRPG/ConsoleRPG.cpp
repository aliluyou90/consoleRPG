// ConsoleRPG.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#include <iostream>
#include "MainMenu.h"
using namespace std;

int main()
{
	srand(time(NULL));
	MainMenu main;
	//Inventory inv;
	Game g;
	g.loadCharacter();

	while (main.getPlaying()) {

		main.mainMenu();

	}


    return 0;
}

