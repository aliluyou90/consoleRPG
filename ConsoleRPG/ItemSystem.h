#pragma once
#include "Inventory.h"
#include "Character.h"
class ItemSystem
{
private:
	bool state;
	Inventory inv;
	int choice;
	Character* character;
public:
	ItemSystem();
	virtual ~ItemSystem();
	void init(Character* character);
	void itemSysManu();
	void itemOninfo();
};

