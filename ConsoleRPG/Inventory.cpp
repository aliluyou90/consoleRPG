#include "stdafx.h"
#include "Inventory.h"


Inventory::Inventory()
{
	this->capacity = 5;
	this->nrofItems = 0;
	this->itemArr = new Item*[capacity];
	this->initItem();
	
}


Inventory::~Inventory()
{
	for (size_t i = 0; i < this->nrofItems; i++) {
		delete this->itemArr[i];
	}
	delete[] this->itemArr;
}

Inventory::Inventory(const Inventory & obj)
{
	this->capacity = obj.capacity;
	this->nrofItems = obj.nrofItems;
	this->itemArr = new Item*[this->capacity];

	for (int i = 0; i < this->nrofItems; i++) {
		this->itemArr[i] = obj.itemArr[i]->clone();
	}
	initItem(this->nrofItems);
}

Item & Inventory::operator[](const int index)
{
	// TODO: insert return statement here
	if (index < 0 || index >= this->nrofItems)
		throw ("Bad Index!");
		return *this->itemArr[index];

}

void Inventory::addItem(const Item & item)
{
	if (this->nrofItems >= this->capacity) {
		this->expand();
	}
	this->itemArr[this->nrofItems++] = item.clone();
}

void Inventory::removeItem(int index)
{
}

void Inventory::initItem(const int from)
{
	for (size_t i = from; i < capacity; i++) {

		this->itemArr[i] = nullptr;
	}
}

void Inventory::expand()
{
	this->capacity *= 2;
	Item** tempArr = new Item*[this->capacity];
	for (size_t i = 0; i < this->nrofItems; i++) {

		tempArr[i] = this->itemArr[i];
	}



	delete[] this->itemArr;

	this->itemArr = tempArr;
	this->initItem(this->nrofItems);

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

