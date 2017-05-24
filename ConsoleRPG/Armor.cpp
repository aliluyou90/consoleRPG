#include "stdafx.h"
#include "Armor.h"


Armor::Armor(int level, int rarity, int numPile)
	: Item(level, rarity , numPile)
{
	this->type = 0;
	this->defence = 0;
	this->material = 0;
	armorLevel = level / 3 + 1;

	this->randgenArmor();

}

Armor::~Armor()
{
}

Armor * Armor::clone() const
{
	return new Armor(*this);
}

string Armor::debugPrint() const
{

	string str = this->getName() + " " + this->getType() + " "
		+ to_string(this->defence) + " Value=  " + to_string(this->getValue())
		+ " Level = " + to_string(this->armorLevel);
	return str;
}

Item * Armor::useItem(Character * character)
{
	Item * it = nullptr;
	switch (this->type) {
	case 1 :
		it = character->getFootOn();
		character->setFootOn(this);
		character->setDefenseFoot(this->defence);
		break;
	case 2:
		it = character->getHeadOn();
		character->setHeadOn(this);
		character->setDefenseHead(this->defence);
		break;
	case 3:
		it = character->getBodyOn();
		character->setBodyOn(this);
		character->setDefenseBody(this->defence);
		break;
	default:
		break;
	}
	cout << this->getName() << "is used" << endl;
	character->setDefense();
	
	return it;

}

void Armor::randgenArmor()
{
	vector<vector<string>> armNameVec = { { "��ͷѥ","��ѥ","��Ь","��Ь" } ,
	{ "Ѽ��ñ","ˮ��ñ","����ñ","����" }  ,
	{ "����", "���" ,"����","����" }
	};
	vector<string> materialVec = { "����","����","Ƥ��","����" };

		this->type = rand() % 3 + 1;
		this->material = rand() % 4 + 1;
		int  index = rand() % 4 + 0;

		this->setName(materialVec[this->material-1]+armNameVec[type-1][index]);
		this->setDefense();
		;
		this->setValue((rand() % 33 + 1)* pow(2, this->armorLevel / 2 + 1) / 22 * this->getRarity());


}

void Armor::setDefense()
{
	this->defence = this->armorLevel * this->getLevel() * this->type * this->getRarity()*this->material;


}


