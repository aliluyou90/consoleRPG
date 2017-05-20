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
	this->playing = true;
	this->createNewCharacter();
	
}


void Game::createNewCharacter()
{
	cin . ignore();
	string name;
	cout << "Enter name for your character: ";
	
	getline(cin, name);

	this->character.initialize(name);
}
void Game::loadCharacter()
{
	this->playing = true;
	string line;
	ifstream inFile(fileName);

	double xPos, yPos;
	string name;
	int level, exp, hp, stamina, strength, vitality, dexterity, intelligence;
	int gold, distanceTravelled;

	if (inFile.is_open())
	{
		inFile >> name >> xPos >> yPos >> level >> exp
			>> hp >> stamina >> strength >> vitality >> dexterity >> intelligence >> gold >> distanceTravelled;
		this->character.initialize(name, hp, stamina, xPos, yPos, distanceTravelled,
			gold, level, exp, strength, vitality,
			dexterity, intelligence);
		
	}

	
	
}
void Game::saveCharacter()
{

	std::ofstream outFile(fileName);
		if (outFile.is_open()) {

				outFile << character.getAsString() << "\n";
			
		}
		outFile.close();

}
void Game::Travel()
{



	int step = 0;

	while (step < rand() % 4) {
		this->character.travel();
		_sleep(1000);
		printf("Travelling (%d EXP)\n",character.getLevel());
		_sleep(1000);
		step++;
	}

	Event ev;
	ev.generateEvent(this->character);

	

}
void Game::mainMenu()
{
	if (!character.isAlive()) { this->playing = false; }
	else {
		cout << "Main Menu" << endl;
		cout << "1: Travel" << endl;
		cout << "2: Shop" << endl;
		cout << "3: Level up" << endl;
		cout << "4: Check Status" << endl;
		cout << "5: Save game" << endl;
		cout << "0: Quit" << endl;
		cout << endl;
		cout << "What is your choice?" << endl;

		cin >> choice;
		cout << endl;
		switch (choice) {
		case 0:
			playing = false;
			break;
		case 1:
			this->Travel();
			break;
		case 4:
			character.printStatus();
			break;
		case 5:
			saveCharacter();
			break;
		default:
			break;
		}
	}
}


//functions
