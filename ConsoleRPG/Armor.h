#pragma once
#include "Item.h"

class Armor :public Item
{
private :
	int type;
	int defence;
	int armorLevel;
	int material;

public:
	Armor(int level = 1,int rarity = 1, int numPile =1);
	virtual ~Armor();

	virtual Armor* clone() const;
	virtual string debugPrint() const;

	//解决使用Item的问题
	virtual Item* useItem(Character* character) ;
	virtual void itemInterface() {};
	
	inline string getType() const {
		string typeName[] = { "Foot","Head","Body" };
		return typeName[this->type-1];
	
	}

	void randgenArmor();
	void setDefense();



};

