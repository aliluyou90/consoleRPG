#include "stdafx.h"
#include "MainMenu.h"





MainMenu::MainMenu()
{

	choice = 0;
	playing = true;

}

void MainMenu::mainMenu()
{

	cout << " = Main Menu = " << endl;
	cout << "1: New Game" << endl;
	cout << "2: Load Game" << endl;
	cout << "3: Quit" << endl;

	cout << endl;
	cout << "What is your choice?" << endl;

	cin >> choice;
	cout << endl;
	switch (choice) {

	case 1:
	
		this->startGame();
		break;

	case 2:
		this->loadGame();
		break;

	case 3:
		this->playing = false;
		break;

	default:
		break;
	}



}



void MainMenu::startGame()
{

	this->game.initGame();

	

	while (game.getPlaying())
		game.mainMenu();

}

void MainMenu::loadGame()
{
	game.loadCharacter();
	while (game.getPlaying())
		game.mainMenu();
}


MainMenu::~MainMenu()
{
}
