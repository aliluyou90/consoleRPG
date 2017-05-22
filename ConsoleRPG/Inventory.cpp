#include "stdafx.h"
#include "Inventory.h"


Inventory::Inventory()
{
	this->capacity = 50;
	this->nrofItems = 0;
	this->itemArr = new vector<Item*>;

	
}


Inventory::~Inventory()
{
	for (size_t i = 0; i < this->nrofItems; i++) {
		delete (*(this->itemArr))[i];
	}
	delete this->itemArr;
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
		return *(*this->itemArr)[index];

}

void Inventory::addItem(const Item & item)
{
	
	if(nrofItems++>50) return;
	(*this->itemArr).push_back ( item.clone());
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
	w.genWeapon();
	this->addItem(w);
	

}

