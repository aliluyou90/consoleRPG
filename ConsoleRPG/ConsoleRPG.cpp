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
	/*
	int res,weaponLevel;
	int level = 1, rarity = 1;
	while (level < 30) {
		weaponLevel = (level / 10) + 1;
		res = static_cast<int>((weaponLevel - 1) * level + rand() % level*(10 + rarity) / 10 * 0.8)+1;
		cout << res << endl;
		level++;
	}*/

		while (main.getPlaying()) {

 		main.mainMenu();

	}


    return 0;
}

