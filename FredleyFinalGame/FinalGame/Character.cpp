#include "stdafx.h"
#include "Character.h"


// Default Constructor
Character::Character()
{
	name = "";
	inventory;
	roomIn = 1;
}

// Overloaded Constructor
Character::Character(string pName, vector<Items> pInventory, int pRoomIn)
{
	name = pName;
	inventory = pInventory;
	roomIn = pRoomIn;
}

// Accessor Mutators
string Character::getName()
{
	return name;
}
void Character::setName(string pName)
{
	name = pName;
}
vector<Items> Character::getInventory()
{
	return inventory;
}
void Character::setInventory(Items pInventory)
{
	inventory.push_back(pInventory);
}
int Character::getRoom()
{
	return roomIn;
}
void Character::setRoom(int pRoom)
{
	roomIn = pRoom;
}