#include "stdafx.h"
#include "Enemy.h"


Enemy::Enemy(int level)
{
	this->level = level;
	this->hpMax = level * 10;
	this->hp = hpMax;
	this->demageMin = this->level * 4;
	this->demageMax = this->level * 5;
	this->defence = rand() % 100;
	this->accuracy = rand() % 100;
	this->dropChance = rand() % 100;
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
