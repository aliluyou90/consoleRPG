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

	void printStatus() const;
	void levelUp();

	void battle(Enemy& enemy);
	void statusUpdate(int exp = 0, int gold = 0);
	
	void useStatPoint();
	string getAsString() const;

	void initialize(string name, int hp = 0, int stamina = 0, double xPos = 0.0, double yPos = 0.0, int distanceTravelled = 0,
		int gold = 10, int level = 1, int exp = 0, int strength = 3, int vitality = 3,
		int dexterity = 3, int intelligence = 3);
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

	inline void takeDemage(int demage) { this->hp -= demage; cout << this->name << " lose" << demage << " HP\n"; }
	inline void winBattle() { cout << this->name << " Won!!" << endl; }
	inline void deadEnd() { cout << "u r dead !\n" ;  }

	// stat update

	inline void setDemage(){
		this->demageMin = static_cast<int>(this->strength*1.5*0.8);
		this->demageMax = static_cast<int>(this->strength*1.5 * 1.2);
	}
	inline void setHpMax() {
		this->hpmax = static_cast<int>(9 * pow(this->level, 1.3) - 4 * pow(this->level, 1.2))+10 + this->hpVita;
		
	}
	inline void setHpVita() { this->hpVita += this->vitality / 4 + 1; }
	// inventory
	void printInvInfo();


private:
	Inventory inventory;
	Weapon *weapon;
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
	int hp,hpmax,hpVita;
	int stamina, staminaMax;
	int demageMin, demageMax;
	int defence;
	int accuracy;
	int statPoints;
	int skillPoints;
	int luck;
	

	


};

