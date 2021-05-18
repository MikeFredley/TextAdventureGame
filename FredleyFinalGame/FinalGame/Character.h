#pragma once
#include <string>
#include <vector>
#include <string>
#include "Room.h"

using namespace std;

class Character
{
private:
	string name;
	vector<Items> inventory;
	int roomIn;
public:
	// Default Constructor
	Character();
	// Overloaded Constructor
	Character(string pName, vector<Items> pInventory, int pRoomin);

	// Accessor Mutators
	string getName();
	void setName(string pName);
	vector<Items> getInventory();
	void setInventory(Items pInventory);
	int getRoom();
	void setRoom(int pRoomin);
};