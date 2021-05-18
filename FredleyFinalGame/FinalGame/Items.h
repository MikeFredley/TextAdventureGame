#pragma once
#include <vector>
#include <string>

using namespace std;
class Items
{
private:
	string name;
	string description;
	bool canKill;
	bool canUse;
	bool hasUsed;
	bool canEquip;
	string itemType;
public:

	// Default constructor
	Items();
	// Overloaded constructor
	Items(string pName, string pDescription, bool pKill, bool pUse, bool pHasUsed, bool pEquip, string pItemType);

	// Accessor and Mutators
	string getName();
	void setName(string pName);
	string getDiscription();
	void setDescription(string pDescription);
	bool getKill();
	void cKill(bool pKill);
	bool getUse();
	void cUse(bool pUse);
	string getType();
	void setType(string pType);
	bool getHasUsed();
	void setHasUsed(bool pUsed);
	// bool pickupItem(string pName, string pDescription, bool pKill, bool pUse, bool pHasUsed, bool pEquip, string pItemType);
};