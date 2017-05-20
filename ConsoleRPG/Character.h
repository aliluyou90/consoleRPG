#pragma once
#include "Inventory.h"
#include "Enemy.h"


using namespace std;
class Character
{
public:
	Character();
	virtual ~Character();

	//function
	void initialize(string name, int hp = 0, int stamina = 0, double xPos = 0.0, double yPos = 0.0, int distanceTravelled = 0,
		int gold = 100, int level = 1, int exp = 0, int strength = 4, int vitality = 4,
		int dexterity = 4,int intelligence = 4);
	void printStatus() const;
	void levelUp();
	void battleAward(int level);
	void battle(Enemy& enemy);
	void statusUpdate(int exp = 0, int gold = 0);
	string getAsString() const;


	//accessors 


	inline const double & getXPos() const {
		return this->xPos;
	}
	inline const double & getYPos() const {
		return this->yPos;
	}

	inline const int& getDistTravel() const { this->distanceTravelled; }
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
	inline int getDemage() const { return  rand() % (this->demageMax - this->demageMin+1) +this->demageMin; }
	inline const int & getDefence() const {
		return this->defence;
	}
	inline const int & getAccuracy() const {
		return this->accuracy;
	}
	//modifier
	inline const bool isAlive()  { return  this->hp > 0; }
	inline void setDistTravel(const int& distance) { this->distanceTravelled = distance; }
	inline void travel() { this->distanceTravelled++; this->exp += this->level; }
private:
	inline void takeDemage(int demage) { this->hp -= demage; cout << this->name << " lose" << demage << " HP\n"; }
	inline void winBattle() { cout << this->name << " Won!!" << endl; }

	inline void deadEnd() { cout << "u r dead !\n" ;  }
	Inventory inventory;
	Weapon weapon;
	Armor armor_head;
	Armor armor_chest;
	Armor armor_arms;
	Armor armor_legs;

	//location
	double xPos;
	double yPos;
	int distanceTravelled;

	string name;
	int level;
	int exp, expNext;
	int strength, vitality, dexterity, intelligence;
	int gold;
	int hp,hpmax;
	int stamina, staminaMax;
	int demageMin, demageMax;
	int defence;
	int accuracy;
	int statPoints;
	int skillPoints;
	int luck;
	

	


};

