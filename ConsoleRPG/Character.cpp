#include "stdafx.h"
#include "Character.h"


Character::Character()
{


	this->xPos = 0.0;
	this->yPos = 0.0;

	this->name  = "NONE";
	this->level = 1;
	this->hpVita = 0;
	this->statPoints = 0;
	this->skillPoints = 0;
	
}


Character::~Character()
{
}

void Character::initialize(const string name, int hp, int stamina , double xPos , double yPos , int distanceTravelled ,
	int gold , int level, int exp, int strength, int vitality ,
	int dexterity , int intelligence )
{
	inventory.getItem(99, 33);
	inventory.getItem(99, 33);
	inventory.getItem(99, 33);
	inventory.getItem(99, 33);
	inventory.getItem(99, 33);
	inventory.getItem(99, 33);
	inventory.getItem(99, 33);
	inventory.getItem(99, 33);
	inventory.getItem(99, 33);
	inventory.getItem(99, 33);

	cout << inventory[3].debugPrint();
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
	this->hpmax = 15;
	if(hp == 0) this->hp = this->hpmax;
	else this->hp = hp;
	this->staminaMax = this->vitality + (this->strength / 2) + (this->dexterity / 3);
	if (stamina == 0) this->stamina = this->staminaMax;
	else this->stamina = stamina;
	

	this->setDemage();
	this->defence = this->dexterity + (this->intelligence / 2);
	this->accuracy = (this->dexterity / 2);
	this->luck = this->intelligence;

}

void Character::useInv()
{
	this->inventory.invInfo();
	bool flag = true;
	int choice = -1;
	
	while (flag) {
cout << "use Item? "<< endl <<"Item Number : Yes \n 0 : Exit" << endl;
		cin >> choice;
		if (choice == 0) { flag = false;}
		else if (choice > 0 && choice < this->inventory.getNumItem()) {
		this->inventory[choice].useItem(this->hp, this->demageMax, this->demageMin, this->defence);
		this->weapon = &this->inventory[choice];

		}
		
	}



}

void Character::printStatus() const
{

	

	cout << " -- Charactar.sheet" << endl;
	cout << " -- Name: " << this->name << "    -- Level: " << this->level ;
	cout << "    -- Exp: " << this->exp <<"/"<< this->expNext << endl;
	cout << " -- Demage: " << this->demageMin << " - " << this->demageMax << endl;
	cout << " -- HP: " << this->hp << "/" << this->hpmax << "   " << "Stamina: " << this->stamina << "/" << this->staminaMax << "   " << "Defence: " << this->defence << endl;
	cout << " -- Luck: " << this->luck << "   " << "Accuracy: " << this->accuracy << endl;
	cout << endl << endl;

}

void Character::levelUp()
{
		this->statPoints += 2;
		this->skillPoints++;
		this->exp -= this->expNext;
		this->level++;
		
		cout << "Level UP! "<< this->level-1 << " -> "<< this->level << endl;
		cout << " == You have 2 more status points.\n" << endl;
		
		this->expNext = static_cast<int>((50 / 3) *(pow(level, 3)
			- 6 * pow(level, 2) + 17 * level - 12))+10;

		this->setHpMax();
		this->hp = this->hpmax;

		this->setDemage();

		

}



void Character::battle(Enemy & enemy)
{
	cout << enemy.getAsString() << endl;
	bool flag = true;
	int round = 0;
	while (flag) {
		int choice = 0;
		cout << " == Battle Menu == " << endl;
		cout << this->name << ": HP = " << this->hp << " / " << this->hpmax;
		cout << "     | " << "Enemy: HP = " << enemy.gethp() << " / " << enemy.gethpMax()<< endl;
		
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
					this->inventory.getItem(enemy.getDropChance(), enemy.getLevel());
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
			cout << "you cannot run like a coward!\n";
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
	cout << "\nYou get " << exp << " exp and " << gold << " gold." << endl;

	
	
	if (this->exp >= this->expNext) {
		this->levelUp();
	}
}


void Character::useStatPoint()
{
	cout << " == Attribute ==" << endl;
	cout << " -- 1. Strength: " << this->strength << "   " << "2. Vitality:  " << this->vitality << endl;
	cout << " -- 3. Dexterity: " << this->dexterity << "   " << "4. Intelligence: " << this->intelligence << endl;
	cout << " == Status Point: " << this->statPoints << endl;

		int choice = 0;
		while (this->statPoints) {
			cout << " Which attribute you want to improve?" << endl;
			cin >> choice;
			this->statPoints--;
			switch (choice) {

			case 1:
				cout << "Strength +1" << endl;
				this->strength++;
				this->setDemage();
				break;
			case 2:
				cout << "Vitality +1" << endl;
				this->vitality++;
				this->setHpVita();
				this->setHpMax();
				break;
			case 3:

				break;
			case 4:

				break;


			default:
				break;
			}
			cout << " == Status Point: " << this->statPoints << endl;
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


