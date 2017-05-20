#pragma once
#include "Game.h"
#include <vector>



class MainMenu
{
private:
	int choice;
	int playing;
	Game game;
public:
	MainMenu();
	void mainMenu();
	void startGame();
	void loadGame();
	virtual ~MainMenu();

	// accessor
	inline bool getPlaying() const { return this->playing; }

};

