#include "stdafx.h"
#include "Items.h"

Items::Items()
{
	name = "";
	description = "";
	canKill = false;
	canUse = false;
}

// Overloaded constructor definition
Items::Items(string pName, string pDescription, bool pKill, bool pUse, bool pHasUsed, bool pEquip, string pItemType)
{
	name = pName;
	description = pDescription;
	canKill = pKill;
	canUse = pUse;
	hasUsed = pHasUsed;
}

// Accessor and Mutators
string Items::getName()
{
	return name;
}
void Items::setName(string pName)
{
	name = pName;
}
string Items::getDiscription()
{
	return description;
}
void Items::setDescription(string pDescription)
{
	description = pDescription;
}
bool Items::getUse()
{
	return canUse;
}
void Items::cUse(bool pUse)
{
	canUse = pUse;
}
bool Items::getKill()
{
	return canKill;
}
void Items::cKill(bool pKill)
{
	canKill = pKill;
}
string Items::getType()
{
	return itemType;
}
void Items::setType(string pType)
{
	itemType = pType;
}
bool Items::getHasUsed()
{
	return hasUsed;
}
void Items::setHasUsed(bool pUsed)
{
	hasUsed = pUsed;
}
