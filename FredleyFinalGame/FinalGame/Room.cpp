#include "stdafx.h"
#include "Room.h"

// Default Constructor
Room::Room()
{
	name = "";
	description = "dark and wet";
	exits = "Northnorth";
	
}


// Overloaded constructor
Room::Room(string pName, string pDescription, string pExits)
{
	name = pName;
	description = pDescription;
	exits = pExits;

}

// Compares the rooms exit to the input from the user
bool Room::checkExits(string pExits, string pInput)
{
	if (pExits.find(pInput) != string::npos)
	{

		return true;
	}
	return false;
}

// Outputs the description of the room.
void Room::look(vector<Items> pItems)
{
	cout << "You enter a room that is " << description << " That has an exit in the " << exits << "." << endl;
	cout << "With the following items:" << endl;
	for (int i = 0; i < pItems.size(); ++i)
	{
		cout << pItems[i].getName() << endl;
	}
	
}


// Accessor Mutators
string Room::getName()
{
	return name;
}
void Room::setName(string pName)
{
	name = pName;
}
string Room::getDescription()
{
	return description;
}
void Room::setDescription(string pDescription)
{
	description = pDescription;
}
string Room::getExits()
{
	return exits;
}
void Room::setExits(string pExits)
{
	exits = pExits;
}
void Room::setInventory(Items pItem)
{
	items.push_back(pItem);
}
vector<Items> Room::getInventory()
{
	return items;
}
