#pragma once
#include <stdlib.h>
#include <string>
using namespace std;
class Enemy
{
private: 
	int level;
	int hp;
	int hpMax;
	int demageMin, demageMax;
	float dropChance;
	int defence;
	int accuracy;
public:
	Enemy(int level = 0);
	virtual ~Enemy();




	inline bool isAlice() { return  this->hp > 0; }
	string getAsString() const;
	inline void takeDemage(int demage) { this->hp -= demage; printf("You enemy lose %d HP! \n", demage); }

	inline int getDemage() const { return rand() % (this->demageMax - this->demageMin+1) + (this->demageMin); }

	//maybe wrong
	inline int gethp() const { return this->hp; }
	inline int gethpMax() const { return this->hpMax; }
	inline int getExp() const { return static_cast<int>(2 * pow(this->level, 2.3)* (rand()%3 +9)/10) + 20;
	}
	inline int getLevel() const { return this->level; }
	inline int getGold() const { return static_cast<int>(pow(this->level, 1.05)* (rand() % 6 + 7) / 10) + 3;
	}
};

