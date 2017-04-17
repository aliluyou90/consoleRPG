#include "stdafx.h"
#include "Event.h"


Event::Event()
{
	this->nrofEvents = 2;

}


Event::~Event()
{
}

void Event::generateEvent()
{

	int i = rand() % this->nrofEvents;

	switch (i) {
		//Enemy encounter
	case 0:
		break;
		// Puzzle
	case 1:
		break;


	case 2:
		break;
	default:
		break;

	}


}
