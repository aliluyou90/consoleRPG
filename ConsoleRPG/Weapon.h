#pragma once
#include"Item.h"
class Weapon : public Item
{

private:
	int demageMin;
	int demageMax;

public:
	Weapon(int demageMin = 0, int demageMax = 0, 
		string name = "NONE", int level = 0, 
		int buyValue=0, int sellValue = 0, int rarity = 0);
	virtual ~Weapon();


	//pure virtual

	virtual Weapon* clone() const;

	string toString();
};

