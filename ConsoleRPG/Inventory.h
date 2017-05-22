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


	//function
	void addItem(const Item & item);
	void removeItem(int index);
	inline int size()const { return this->nrofItems; }
	inline void debugPrint() const {

		for (size_t i = 0; i < this->nrofItems; i++) {
			cout << this->itemArr[i]->debugPrint() << endl;
		}
	}
	void getItem(int dropchance,  int level);
private:
	
	int capacity;
	int nrofItems;
	Item ** itemArr;
	// functions
	void initItem(const int from = 0);
	void expand();
	
};

