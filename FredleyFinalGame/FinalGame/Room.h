#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Items.h"

using namespace std;

class Room
{
private:
	string name;
	string description;
	string exits;
	vector<Items> items;

public:
	// Default Constructor
	Room();
	// Overloaded Constructor
	Room(string pName, string pDescription, string pExits);
	bool checkExits(string pExits, string pInput);
	void look(vector<Items> pItems);

	string getName();
	void setName(string pName);
	string getDescription();
	void setDescription(string pDescription);
	string getExits();
	void setExits(string pExists);
	void setInventory(Items pItem);
	vector<Items> getInventory();
	
};