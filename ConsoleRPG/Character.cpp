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
	this->gold = 0;
	//this->strength = 0;
//	this->intelligence = 0;
	//this->vitality = 0;
	//this->dexterity = 0;


}


Character::~Character()
{
}

void Character::initialize(const string name, int hp, int stamina , double xPos , double yPos , int distanceTravelled ,
	int gold , int level, int exp, int strength, int vitality ,
	int dexterity , int intelligence )
{

	this->xPos = xPos;
	this->yPos = yPos;
	this->distanceTravelled = distanceTravelled;
	this->gold = gold;
	this->name = name;
	this->level = level;
	this->exp = exp;
	this->expNext = static_cast<int>((50/3) *(pow(level,3) 
		- 6 * pow(level,2) + 17*level - 12))+10;
	
	this-> strength = strength, this->vitality = vitality, this->dexterity = dexterity, this->intelligence = intelligence;
	
	this->hpmax = 40;
	if(hp == 0) this->hp = this->hpmax;
	else this->hp = hp;
	this->staminaMax = this->vitality + (this->strength / 2) + (this->dexterity / 3);
	if (stamina == 0) this->stamina = this->staminaMax;
	else this->stamina = stamina;
	

	this->demageMin = static_cast<int>(this->strength*0.8);
	this->demageMax = static_cast<int>(this->strength*1.2);
	this->defence = this->dexterity + (this->intelligence / 2);
	this->accuracy = (this->dexterity / 2);
	this->luck = this->intelligence;

}

void Character::printStatus() const
{

	cout << " -- CHaractar.sheet" << endl;
	cout << " -- Name: " << this->name << "    -- Level: " << this->level ;
	cout << "    -- Exp: " << this->exp <<"/"<< this->expNext << endl;
	cout << " -- Demage: " << this->demageMin << " - " << this->demageMax << endl;
	cout << " -- HP: " << this->hp << "/" << this->hpmax << "   " << "Stamina: " << this->stamina << "/" << this->staminaMax << "   " << "Defence: " << this->defence << endl;
	cout << " -- Strength: " << this->strength << "   " << "Vitality:  " << this->vitality << endl;
	cout<< " -- Dexterity: " << this->dexterity << "   " << "Intelligence: " << this->intelligence << endl;
	cout << " -- Luck: " << this->luck << "   "<< "Accuracy: "<<this->accuracy << endl;
	cout << endl;

}

void Character::levelUp()
{
		this->statPoints++;
		this->skillPoints++;
		this->exp -= this->expNext;
		this->level++;



		this->expNext = static_cast<int>((50 / 3) *(pow(level, 3)
			- 6 * pow(level, 2) + 17 * level - 12))+10;
		this->hpmax = static_cast<int>(9 * pow(this->strength, 1.3) - 4 * pow(this->strength, 1.2)) + 20;
		this->hp = this->hpmax;

		this->demageMin = static_cast<int>(this->strength*1.5*0.8);
		this->demageMax = static_cast<int>(this->strength*1.5 * 1.1);

		cout << "level up!!!\n" << endl;

}

void Character::battleAward(int level)
{

}

void Character::battle(Enemy & enemy)
{
	bool flag = true;
	int round = 0;
	while (flag) {
		int choice = 0;
		cout << " == Battle Menu == " << endl;
		//printf("%s: HP = %d/%d     || Enemy: HP = %d/%d", this->name, this->hp, this->hpmax,enemy.gethp(),enemy.gethpMax());
		cout << "1: Attack" << endl;
		cout << "2: Run\n" << endl;
		cout << endl;
		cout << "What is your choice?\n -->";
		cin >> choice;
		cout << endl;
		switch (choice) {

		case 1:
			_sleep(1000);
			cout << "You attack the enemy bravely!\n";

			while (round < 3) {
				enemy.takeDemage(this->getDemage());
				_sleep(1000);
				if (!enemy.isAlice()) {
					this->winBattle();
					this->statusUpdate(enemy.getExp(), enemy.getGold());
					flag = false;
					break;
				};
				_sleep(1000);
				this->takeDemage(enemy.getDemage());
				if (!this->isAlive()) {
					this->deadEnd();
					flag = false;
					break;
				};
				_sleep(1000);

				round++;
			}
			round = 0;
			break;
		case 2:
			_sleep(1000);
			cout << "you cannot run like a coward!";
			_sleep(1000);
		default:
			break;
		}

	}


	
}

void Character::statusUpdate(int exp, int gold)
{
	this->exp += exp;
	this->gold += gold;
	cout << "You get " << exp << " exp and " << gold << " gold." << endl;
	if (this->exp >= this->expNext) {
		this->levelUp();
	}
}

string Character::getAsString() const
{
	return name + " " +
		to_string(xPos) + " "
		+ to_string(yPos) + " "
		+ to_string(level) + " "
		+ to_string(exp) + " "
		+ to_string(hp) + " "
		+ to_string(stamina) + " "

		+ to_string(strength) + " "
		+ to_string(vitality) + " "
		+ to_string(dexterity) + " "
		+ to_string(intelligence) + " "
		+ to_string(gold) + " "
		+ to_string(distanceTravelled) + " ";
		//+ to_string(statPoints) + " "
		//+ to_string(skillPoints);

}
