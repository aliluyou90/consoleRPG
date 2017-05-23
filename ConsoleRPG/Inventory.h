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
	void addItem(const Weapon & item);
	void Inventory::addItem(const Armor & item);
	void removeItem(int index);
	inline int size()const { return this->nrofItems; }

	inline void weaponPrint() const {
		for (size_t i = 0; i < this->weaponVec.size(); i++) {
			cout << this->weaponVec[i].debugPrint() << endl;
		}
	}
	inline void armorPrint() const {
		for (size_t i = 0; i < this->armorVec.size(); i++) {
			cout << this->weaponVec[i].debugPrint() << endl;
		}
	}





	void getItem(int dropchance,  int level);
	inline int getNumItem() const{ return this->nrofItems; }


private:
	
	int capacity;
	int nrofItems;

	vector<Weapon>  weaponVec;
	vector<Armor>  armorVec;
	
	
	// functions

	
};

