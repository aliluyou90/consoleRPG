#include "stdafx.h"
#include "ItemSystem.h"


ItemSystem::ItemSystem()
{
}


ItemSystem::~ItemSystem()
{
}

void ItemSystem::init(Character* character)
{
	this->character = character;
	 this->state = true;
	 while (this->state) {
		 this->itemSysManu();
	 }
}



void ItemSystem::itemSysManu()
{

	this->itemOninfo();
	this->inv.invInfo(); 
	cout << " -------------> Select (Item #) or Back(0)" << endl;
	
	choice = 0;
	cin >> choice;
	if (choice == 0) { this->state = false; }
	else if (choice <= this->inv.getNumItem()) {
		
		cout << this->inv[choice-1].debugPrint()<< endl;
		
		int useOrnot = 0;
		cout << "\n======= 1:Use Item \n======= 2:Discard Item \n======= Other: Back\n -->";
		cin >> useOrnot;
		switch(useOrnot){
		case 1:
			 
		{Item * it = this->inv[choice - 1].useItem(character);
		if (it) {
			this->inv.addItem(*it);
		}
		this->inv.removeItem(choice - 1); }
			break;
		case 2:
			this->inv.removeItem(choice - 1);
			break;
		default:
			break;
		}
	}
	


}

void ItemSystem::itemOninfo()
{
	Item * it;
	cout << "===================================================================\n";
	it = character->getWeaponOn();
	if (it) {
		cout << " == Weapon: " +it->getName() << " ";
	}
	else { cout << " == Weapon: empty" << " "; }
	it = character->getHeadOn();
	if (it) {
		cout << " == Head: " + it->getName() << " ";
	}
	else { cout << " == Head: empty" << " "; }

	it = character->getBodyOn();
	if (it) {
		cout << " == Body: " + it->getName() << " ";
	}
	else { cout << " == Body: empty" << " "; }
	it = character->getFootOn();
	if (it) {
		cout << " == Foot: " + it->getName() << "   ";
	}
	else { cout << " == Foot: empty" << "   "; }

	cout << endl << "===================================================================\n\n";
}


