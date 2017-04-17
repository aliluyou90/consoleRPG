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
	inline void takeDemage(int demage) { this->hp -= demage; }
	inline int getDemage() const{ return rand() % this->demageMax - this->demageMin; }
	//maybe wrong
	inline int getExp() const { return this->level * 100; }
};

