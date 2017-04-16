#include "stdafx.h"
#include "Game.h"


Game::Game()
{
	choice = 0;
	playing = true;
	activeCharacter = 0;
	fileName = "characters.txt";

}


Game::~Game()
{
}
void Game::initGame() {
	this->createNewCharacter();
	Weapon w1(2, 5, "DDK", 1, 100, 100, 1);
	cout << w1.toString();

}


void Game::createNewCharacter()
{
	string name;
	cout << "Enter name for your character: ";
	
	getline(cin, name);

	characters.push_back(Character());
	activeCharacter = characters.size() - 1;
	characters[activeCharacter].initialize(name);
}
void Game::loadCharacter()
{
}
void Game::saveCharacter()
{

	std::ofstream outFile(fileName);
		if (outFile.is_open()) {

			for (size_t i = 0; i < characters.size(); i++) {
				outFile << characters[i].getAsString() << "\n";
			}

		}
		outFile.close();

}
void Game::mainMenu()
{
	cout << "Main Menu" << endl;
	cout << "0: Quit" << endl;
	cout << "1: Travel" << endl;
	cout << "2: Shop" << endl;
	cout << "3: Level up" << endl;
	cout << "4: Rest" << endl ;
	cout << "5: Character sheet" << endl;
	cout << "6: Create new character" << endl;
	cout << "7: Save character" << endl;
	cout << "8: Load character";
	cout<< endl;
	cout << "What is your choice?" << endl;

	cin >> choice;
	cout << endl;
	switch (choice) {
	case 0:
		playing = false;
		break;
	case 5:
		characters[activeCharacter].printStatus();
		break;
	case 6:
		cin.ignore();
		createNewCharacter();
		saveCharacter();
		break;
	case 7:
		
		saveCharacter();
		break;
	case 8:
		
		loadCharacter();
		break;
	default:
		break;
	}
}


//functions
