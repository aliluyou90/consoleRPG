#pragma once
#include "Inventory.h"


using namespace std;
class Character
{
public:
	Character();
	virtual ~Character();

	//function
	void initialize(string name);
	void printStatus() const;
	void levelUp();
	string getAsString() const;


	//accessors 
	inline const double & getXPos() const {
		return this->xPos;
	}
	inline const double & getYPos() const {
		return this->yPos;
	}


	inline const string & getName() const {
		return this->name;
	}

	inline const int & getLevel() const {
		return this->level;
	}
	inline const int & getExp() const {
		return this->exp;
	}
	inline const int & getExpNext() const {
		return this->expNext;
	}
	inline const int & getHP() const {
		return this->hp;
	}
	inline const int & getHPmax() const {
		return this->hpmax;
	}
	inline const int & getStamina() const {
		return this->stamina;
	}


	inline const int & getDemageMax() const {
		return this->demageMax;
	}
	inline const int & getDemageMin() const {
		return this->demageMin;
	}

	inline const int & getDefence() const {
		return this->defence;
	}
	
	//modifier

private:
	
	//location
	double xPos;
	double yPos;
	Inventory inventory;
	Weapon weapon;
	Armor armor_head;
	Armor armor_chest;
	Armor armor_arms;
	Armor armor_legs;

	string name;
	int level;
	int exp, expNext;
	int strength, vitality, dexterity, intelligence;

	int hp,hpmax;
	int stamina, staminaMax;
	int demageMin, demageMax;
	int defence;
	int statPoints;
	int skillPoints;
	int luck;
	

	


};

