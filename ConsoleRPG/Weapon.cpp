#include "stdafx.h"
#include "Weapon.h"




Weapon::Weapon(int level, int rarity, int numPile) 
: Item(level, rarity, numPile)
{
	this->demageMax = 0;
	this->demageMin = 0;
	this->weaponLevel = 1 + level / 3;



}

Weapon::~Weapon()
{
}

void Weapon::genWeapon()
{
	string weaptype[] = { "Sword","Axe","Harmer" };
	int type = rand()%3 + 0;

	this->setName( weaptype[type]);
	this->setDemage(type);
	;
	this->setValue((rand()%33 +1)* pow(2, this->weaponLevel/2+1)/11*this->getRarity());
	
	
	

}

Weapon * Weapon::clone() const
{
	return new Weapon(*this);
}

void Weapon::setDemage(int type)
{
	this->demageMin= static_cast<int>((3-type) * ((this->getLevel() -1) * this->getRarity() + (rand() % this->weaponLevel+1) * this->getRarity()  )/ 10+ this->weaponLevel*this->getRarity()/3) +1;
	this->demageMax = this->demageMin + static_cast<int>( (rand() % this->weaponLevel + 1)* this->getRarity()*(type+1)/3 ) +1;
}

string Weapon::debugPrint() const
{
	string str = this->getName() + " "  + to_string(this->demageMin) + " "
		+ to_string(this->demageMax) + " Value=  "+ to_string(this->getValue())
		+ " Level = " + to_string(this->weaponLevel);
	return str;
}

vector<int> Weapon::useItem()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(this->demageMin);
	v.push_back(this->demageMax);
	return vector<int>();
}






