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
