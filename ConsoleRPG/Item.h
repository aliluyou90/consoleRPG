#pragma once

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Item
{
private:
	string name;
	int level;
	int buyValue;
	int sellValue;
	int rarity;
	

public:
	Item(string name = "NONE", int level = 0, int buyValue = 0, int sellValue = 0,int rarity = 0);
	virtual ~Item();

	inline string debugPrint() const {
		return this->name;
	}
	virtual Item* clone() const = 0;
	// accessors
	inline const string& getName() const { return this->name; };
	inline const int& getLevel() const { return this->level; };
	inline const int& getBuyValue() const { return this->buyValue; };
	inline const int& getSellValue() const { return this->sellValue; };
	inline const int& getRarity() const { return this->rarity; };
	
	
	//modifiers


};

