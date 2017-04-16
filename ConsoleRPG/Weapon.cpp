#include "stdafx.h"
#include "Weapon.h"




Weapon::Weapon(int demageMin, int demageMax, string name, int level, int buyValue, int sellValue, int rarity) 
: Item(name, level, buyValue,sellValue,rarity)
{
	this->demageMax = demageMax;
	this->demageMin = demageMin;
}

Weapon::~Weapon()
{
}

Weapon * Weapon::clone() const
{
	return new Weapon(*this);
}

string Weapon::toString()
{
	string str = to_string(this->demageMin) + " "
		+ to_string(this->demageMax);
	return str;
}
