#include "stdafx.h"
#include "Enemy.h"


Enemy::Enemy(int level)
{
	this->level = level;
	this->hpMax = static_cast<int>((9 * pow(level, 1.3) - 4 * pow(level, 1.2)) / 10 * (rand() % 3 + 5)) + 10;
	this->hp = hpMax;
	this->demageMin = static_cast<int>(this->level * (rand()%3 +6))/10 + (rand() % 2 +1);
	this->demageMax = static_cast<int>(this->demageMin*1.2);
	this->defence = rand() % 100;
	this->accuracy = 0.75;
	this->dropChance = 25;

}


Enemy::~Enemy()
{

}


string Enemy::getAsString() const
{
	return "Level: " + to_string(this->level) +
		"Hp: " + to_string(this->hp) + "/" + to_string(this->hpMax) +
		"Demage: " + to_string(this->demageMin) + "-" +to_string(this->demageMax) +
		"Defence: " + to_string(this->defence) +
		"Accuracy: " + to_string(this->accuracy) +
		"Drop chance: " + to_string(this->dropChance);
		;
}
