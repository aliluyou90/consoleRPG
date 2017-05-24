#pragma once
#include "Weapon.h"
#include "Armor.h"
// item container
class Inventory
{
public:
	Inventory();
    ~Inventory();
	Inventory(const Inventory &obj);
	//overload operator
	Item& operator[](const int index);
	void invInfo();

	//function
	void addItem(const Item & item);

	void removeItem(int index);
	inline int size()const { return this->nrofItems; }

	void getItem(int dropchance,  int level);
	inline int getNumItem() const{ return this->nrofItems; }
	Item* itemFactory(int dropchance, int level);

private:
	
	int capacity;
	int nrofItems;
	vector<Item*>  itemVec;

	
	
	
	// functions

	
};

