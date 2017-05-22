#include "stdafx.h"
#include "Item.h"



Item::Item(int level, int rarity, int numPile)
{
	this->name = "NONE";
	this->level = level;
	this->Value = static_cast<int>(pow(level,2) * 3 + pow(rarity,1.5)*2);
	this->rarity = rarity;
	this->numPile = numPile;
}

Item::~Item()
{
}

void Item::setName( string name)
{
	string rar[] = { "Bad","Regular","Good","Excellent","Legend" };

	this->name = rar[this->rarity - 1] +" "+ name;

}

void Item::setValue(int extra=0)
{
	this->Value += extra;
}
