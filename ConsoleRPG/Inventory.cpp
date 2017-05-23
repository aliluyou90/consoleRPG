#include "stdafx.h"
#include "Inventory.h"


Inventory::Inventory()
{
	this->capacity = 50;
	this->nrofItems = 0;


	
}


Inventory::~Inventory()
{
	
}

Inventory::Inventory(const Inventory & obj)
{
	/*this->capacity = obj.capacity;
	this->nrofItems = obj.nrofItems;
	this->itemArr = new vector<Item>*[this->capacity];

	for (int i = 0; i < this->nrofItems; i++) {
		this->itemArr[i] = obj.itemArr[i]->clone();
	}
	initItem(this->nrofItems);
	*/
	}

Item & Inventory::operator[](const int index)
{
	// TODO: insert return statement here
	if (index < 0 || index >= this->nrofItems)
		throw ("Bad Index!");
		return this->weaponVec[index];

}

void Inventory::invInfo()
{
	cout << "1 : weapon 2 : armor \n";
	int choice = 0;
	cin >> choice;
	switch (choice) {
	case 1 :
		this->weaponPrint();
			break;
	case 2 :
		this->armorPrint();
			break;

	default:
		break;
	}
}

void Inventory::addItem(const Weapon & item)
{
	
	if(nrofItems++>this->capacity) return;
	this->weaponVec.push_back ( *item.clone());
}
void Inventory::addItem(const Armor & item)
{

	if (nrofItems++>this->capacity) return;
	this->armorVec.push_back(*item.clone());
}


void Inventory::removeItem(int index)
{

	nrofItems--;
}




void Inventory::getItem(int dropchance,int level)
{
	if (rand() % 100 > dropchance) { return; }
	int rarity, randnum = rand() % 100;
	if (randnum<5) {
		rarity = 5;
	}
	else if (randnum >= 5 && randnum < 15) { rarity = 4; }
	else if (randnum >= 15 && randnum < 30) { rarity = 3; }
	else if (randnum >= 30 && randnum < 50) { rarity = 2; }
	else { rarity = 1; }

	Weapon w(level,rarity);

	this->addItem(w);
}

