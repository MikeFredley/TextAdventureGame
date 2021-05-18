#pragma once
#include <string>
#include <vector>
#include "Items.h"
using namespace std;

class Enemy 
{
private:
	string name;
	string description;
	string voice;
	int health;
	vector<Items> inventory;
public:

	// Constructor
	Enemy();

	// Overloaded constructor
	Enemy(string pName, string pDescription, string pVoice, int pHealth);

	// Accessor and Mutators
	string getName();
	void setName(string pName);
	string getDescription();
	void setDescription(string pDescription);
	string getVoice();
	void setVoice(string pVoice);
	int getHealth();
	void setHealth(int pHealth);
	vector<Items> getInventory();
	void setInventory(Items pInventory);
};