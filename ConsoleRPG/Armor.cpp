#include "stdafx.h"
#include "Armor.h"


Armor::Armor(int type, int defence, string name, int level, int buyValue, int sellValue, int rarity)
{
	this->type = type;
	this->defence = defence;
}

Armor::~Armor()
{
}

Armor * Armor::clone() const
{
	return new Armor(*this);
}

string Armor::debugPrint() const
{
	string str =  to_string(this->type) + " " 
		+ to_string(this->defence);
	return str;
}

vector<int> Armor::useItem()
{
	return vector<int>();
}
