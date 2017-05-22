#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

class Item
{
private:
	string name;
	int level;
	int Value;
	int rarity;
	int numPile;
	

public:
	Item( int level = 1, int rarity = 1, int numPile = 1);
	virtual ~Item();

	virtual string debugPrint() const {
		return this->name + " " + to_string(this->Value);
	}
	virtual Item* clone() const = 0;
	virtual vector<int> useItem() = 0;
	
	// accessors
	inline const string& getName() const { return this->name; };
	inline const int& getLevel() const { return this->level; };
	inline const int& getValue() const { return this->Value; };
	
	inline const int& getRarity() const { return this->rarity; };
	
	
	//modifiers
	virtual void setName( string name);
	virtual void setValue(int extra);
};

