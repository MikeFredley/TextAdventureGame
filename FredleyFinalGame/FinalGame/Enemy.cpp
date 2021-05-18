#include "stdafx.h"
#include "Enemy.h"

// Default constructor defintion
Enemy::Enemy() 
{
	name = "";
	description = "";
	voice = "";
	health = 50;
}

// Overloaded constructor definition
Enemy::Enemy(string pName, string pDescription, string pVoice, int pHealth) 
{
	name = pName;
	description = pDescription;
	voice = pVoice;
	health = pHealth;
}

// Accessor and Mutators
string Enemy::getName() 
{
	return name;
}
void Enemy::setName(string pName) 
{
	name = pName;
}
string Enemy::getDescription() 
{
	return description;
}
void Enemy::setDescription(string pDescription)
{
	description = pDescription;
}
string Enemy::getVoice() 
{
	return voice;
}
void Enemy::setVoice(string pVoice) 
{
	voice = pVoice;
}
int Enemy::getHealth() 
{
	return health;
}
void Enemy::setHealth(int pHealth) 
{
	health = pHealth;
}
vector<Items> Enemy::getInventory()
{
	return inventory;
}
void Enemy::setInventory(Items pInventory)
{
	inventory.push_back(pInventory);
}
