#pragma once
#include"Item.h"
#include <string>

class Weapon : public Item
{

private:
	int demageMin;
	int demageMax;
	int weaponLevel;

public:
	Weapon(int level = 1,  int rarity = 1, int numPile = 1);
	virtual ~Weapon();
	void genWeapon();

	//pure virtual

	virtual Weapon* clone() const;
	void setDemage(int type);
	string debugPrint() const;
	Item* useItem(Character* character);
	
	void itemInterface();
};

