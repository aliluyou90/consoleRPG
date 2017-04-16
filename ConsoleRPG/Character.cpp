#include "stdafx.h"
#include "Character.h"


Character::Character()
{


	this->xPos = 0.0;
	this->yPos = 0.0;

	this->name  = "NONE";
	this->level = 1;
	this->exp = 0;
	this->expNext = 0;
	this->hp=0, hpmax=0;
	this->stamina = 0;
	this->demageMin = 0, demageMax = 0;
	this->defence = 0;
	this->statPoints = 0;
	this->skillPoints = 0;
	//this->strength = 0;
//	this->intelligence = 0;
	//this->vitality = 0;
	//this->dexterity = 0;


}


Character::~Character()
{
}

void Character::initialize( const string name)
{

	this->xPos = 0.0;
	this->yPos = 0.0;


	this->name = name;
	this->level = 1;
	this->exp = 0;
	this->expNext = static_cast<int>((50/3) *(pow(level,3) 
		- 6 * pow(level,2) + 17*level - 12))+10;
	
	this-> strength = 5, this->vitality = 5, this->dexterity = 5, this->intelligence = 5;
	
	this->hpmax = (this->vitality * 2) + (this->strength / 2);
	this->hp = hpmax;
	this->staminaMax = this->vitality + (this->strength / 2) + (this->dexterity / 3);
	this->stamina = this->staminaMax;
	this->demageMin = this->strength;
	this->demageMax = this->strength + 2;
	this->defence = this->dexterity + (this->intelligence / 2);
	this->luck = this->intelligence;

}

void Character::printStatus() const
{

	cout << " -- CHaractar.sheet" << endl;
	cout << " -- Name: " << this->name << endl;
	cout << " -- Level: " << this->level << endl;
	cout << " -- Exp: " << this->exp <<"      " <<"Exp to next Level: " << this->expNext << endl;
	//cout << setw(100)<<setfill('-')<< endl;
	cout << " -- HP: " << this->hp << "/" << this->hpmax << "   " << "Stamina: " << this->stamina << "/" << this->staminaMax << "   " << "Defence: " << this->defence << endl;
	cout << " -- Strength: " << this->strength << "   " << "Vitality:  " << this->vitality << endl;
	cout<< " -- Dexterity: " << this->dexterity << "   " << "Intelligence: " << this->intelligence << endl;
	cout << " -- Luck: " << this->luck << endl;
	cout << endl;

}

void Character::levelUp()
{
	while (this->exp >= this->expNext) {
		
		this->exp -= this->expNext;
		this->level++;
		this->expNext = static_cast<int>((50 / 3) *(pow(level, 3)
			- 6 * pow(level, 2) + 17 * level - 12))+10;
		this->statPoints++;
		this->skillPoints++;
	}

}

string Character::getAsString() const
{
	return to_string(xPos) + " "
		+ to_string(yPos) + " "
		+ name + " "
		+ to_string(level) + " "
		+ to_string(exp) + " "
		+ to_string(strength) + " "
		+ to_string(vitality) + " "
		+ to_string(dexterity) + " "
		+ to_string(intelligence) + " "
		+ to_string(hp) + " "
		+ to_string(stamina) + " "
		+ to_string(statPoints) + " "
		+ to_string(skillPoints);

}
