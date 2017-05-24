#include "stdafx.h"
#include "Inventory.h"


Inventory::Inventory()
{
	this->capacity = 50;
	this->nrofItems = 0;
	this->getItem(99, 1);
	this->getItem(99, 1);
	this->getItem(99, 1);
	this->getItem(99, 1);
	this->getItem(99, 1);
	this->getItem(99, 1);
	this->getItem(99, 1);
	this->getItem(99, 1);
	this->getItem(99, 1);
	this->getItem(99, 1);
	this->getItem(99, 1);
	this->getItem(99, 1);

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
		return *this->itemVec[index];

}

void Inventory::invInfo()
{
	cout << "==========  Inventory  ===========" << endl;
	for (size_t i = 0; i < this->nrofItems; i++) {
		cout << "--- "<<i+1<< ": " <<this->itemVec[i]->getName() << endl;
	}
	cout << "==================================" << endl;
}

void Inventory::addItem(const Item & item)
{
	
	if(nrofItems++>this->capacity) return;
	this->itemVec.push_back ( item.clone());
}


void Inventory::removeItem(int index)
{
	vector<Item*>::iterator it = this->itemVec.begin()+index ;

	this->itemVec.erase(it);


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

	;

	this->addItem(*this->itemFactory(level, rarity));
}

Item* Inventory::itemFactory(int level, int rarity)
{
	Item * item = nullptr;
	int res = rand() % 2;
	
	if (res == 0) { item = new Weapon(level, rarity);
	}
	else {
		item = new Armor(level, rarity);
	}

	return item;


}

