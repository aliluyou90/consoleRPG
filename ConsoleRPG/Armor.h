#pragma once
#include "Item.h"
class Armor :public Item
{
private :
	int type;
	int defence;

public:
	Armor(int type = 0, int defence = 0, string name = "NONE",
		int level = 0,
		int buyValue = 0, int sellValue = 0, int rarity = 0);
	virtual ~Armor();

	virtual Armor* clone() const;
	virtual string debugPrint() const;

	//解决使用Item的问题
	virtual void useItem(int& hp, int& demageMax, int& demageMin, int& defense) {};
};

