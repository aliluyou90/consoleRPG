#pragma once
#include "Character.h"
#include <ctime>
#include <vector>
#include <fstream>
using namespace std;


class Game
{
public:
	Game();
	virtual ~Game();
	//functions
	void mainMenu();
	void initGame();
	void createNewCharacter();
	void loadCharacter();
	void saveCharacter();
	//operators

	//accessors
	inline bool getPlaying() const { return this->playing; }
	//Modifiers
private:
	int choice;
	bool playing;

	//character related
	int activeCharacter;
	vector<Character> characters;
	string fileName;
	
};

