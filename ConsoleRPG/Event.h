#pragma once
#include <stdlib.h>
#include "Puzzle.h"
#include "Character.h"


class Event
{
private:
	int nrofEvents;
	

public:
	Event();
	virtual ~Event();
	void generateEvent(Character& character);
	void getEnemy(int level);

};

