#include "stdafx.h"
#include "Event.h"


Event::Event()
{
	this->nrofEvents = 2;

}


Event::~Event()
{

}

void Event::generateEvent(Character & character)
{

	int i = rand() % this->nrofEvents;

	switch (i) {
		//Enemy encounter
	case 0:
		cout << "see enemy\n" << endl;
		
		{Enemy enemy(character.getLevel()); 
		character.battle(enemy);
		
		}
		
		break;
		// Puzzle
	case 1:
		cout << "see problems\n" << endl;
		//character.puzzleAward();
		break;


	case 2:
		break;
	default:
		break;

	}


}

void Event::getEnemy(int level)
{
	Enemy enemy(level);
	

}




