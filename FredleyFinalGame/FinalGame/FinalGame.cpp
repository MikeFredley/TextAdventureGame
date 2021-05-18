
/*Authors: Isaac Hartzell and Michael Fredley
 *Purpose: To make us old and grey
 *To create a Zork like text adventure game
 *that uses vectors and object/classes in c++
 */
#include "stdafx.h"
#include "Room.h"
#include "Enemy.h"
#include <string>
#include <iostream>
#include "Character.h"
#include <regex>
#include <cstdlib>
using namespace std;

//shows the content of the room by passing the vector of object into the room
void look(Room pRoom)
{
	pRoom.look(pRoom.getInventory());
}

void showDisplay()
{
	//Shows the cout for each of the commands
	//note how we can take either upper case and lower case
	cout << "Movement Commands:" << endl;
	cout << "    " << "North or north.....Takes You North" << endl;
	cout << "    " << "East  or east......Takes You East" << endl;
	cout << "    " << "West  or west......Takes You West" << endl;
	cout << "    " << "South or south.....Takes You South" << endl;
	cout << " Player Commands: " << endl;
	cout << "    " << "Look  or look.....Shows the contents and description of the room." << endl;
	cout << "    " << "Exits or exits....Shows all the exits in the current room." << endl;
	cout << "    " << "Pickup or pickup....Enables you to pick up an item." << endl;
	cout << "    " << "North or north....Takes You North" << endl;
	cout << "    " << "Hit or hit....Hit Stuff With Stuff" << endl;
	cout << "    " << "Talk or talk......You are a silent champion, but who knows..maybe you will speak..." << endl;
	cout << "    " << "Display or diplay........shows all this crap" << endl;
	cout << "    " << "kill Jody.....kills Jody" << endl;
	cout << "    " << "free Jody.....frees Jody" << endl;
	cout << "------------------------------------------------------------------------------------------------------------\n\n";
}

/*
 * Holds all the logic for the Jody encounter.
 * Checks the character's inventory and then ends the game based on the final choice
 */
void jodyEncounter(Character &pPlayer, Enemy pJody, Items &pbeer)
{
	string input;
	cout << "As you enter the room you notice a massive cage in the corner" << endl;
	cout << "In the cage you see " << pJody.getName() << " " << pJody.getDescription() << endl;
	cout << pJody.getName() << " says " << pJody.getVoice() << endl;
	cout << "**You can choose between killing Jody or freeing him from the cage**" << endl;
	cout << "What would you like to do?" << endl;
	getline(cin, input);
	if (input == "kill Jody")
	{
		//Checks if the invenoty is empty before we loop through it - both loops the same for the sword and the key
		if (pPlayer.getInventory().size() != 0)
		{
			for (int i = 0; i < pPlayer.getInventory().size(); ++i)
			{
				if (pPlayer.getInventory()[i].getName() == "Sword")
				{
					cout << "Jody dies and drops some beer" << endl;
					pPlayer.setInventory(pJody.getInventory()[0]);
					cout << "You finally got your beer!" << endl;
					cout << "You take a big long drink and your journey comes to an end." << endl;
					cout << "Press enter to close the game." << endl;
					cin.get();
					exit(0);
				}
			}
		}
		else
		{
			cout << "You do not have the sword to kill Jody." << endl;
		}

		
	}
	else if (input == "free Jody")
	{
		//cout << "this works" << endl;
		if (pPlayer.getInventory().size() != 0)
		{
			for (int i = 0; i < pPlayer.getInventory().size(); ++i)
			{
				if (pPlayer.getInventory()[i].getName() == "Key")
				{
					cout << "You free Jody and he gives you some beer.";
					pPlayer.setInventory(pJody.getInventory()[0]);
					cout << "You finally got your beer!" << endl;
					cout << "You take a big long drink and your journey comes to an end." << endl;
					cout << "Press enter to close the game." << endl;
					cin.get();
					exit(0);
				}
			}
		}
		else
		{
			cout << "You do not have the key to open the cage." << endl;
		}
		
	}
	
}

//Checks the exits in each room to determine if we can move that direction
void checkExits(Room pRoom, string pInput, Character &pPlayer)
{

	bool check = pRoom.checkExits(pRoom.getExits(), pInput);

	// Allows or doesnt allow you to do things depending on return of bool variable
	if (check == true)
	{
		cout << "You go " << pInput << endl;
		if (pPlayer.getRoom() == 1)
		{
			pPlayer.setRoom(2);
		}
		else if (pPlayer.getRoom() == 2)
		{
			if (pInput == "west")
			{
				pPlayer.setRoom(1);
			}
			else if (pInput == "south")
			{
				pPlayer.setRoom(3);
			}
		}
		else if (pPlayer.getRoom() == 3)
		{
			if (pInput == "north")
			{
				pPlayer.setRoom(2);
			}
		}
	}
	else
	{
		cout << "You cannot go " << pInput << endl;
	}
}


// Pickup function
void pickup(Room pRoom, Character &pPlayer)
{
	string input;
	// Gets input and passes to the pickup function
	getline(cin, input);
	// Iterates throught the inventory vector of the room object
	for (int i = 0; i < pRoom.getInventory().size(); i++)
	{
		
		// checks to see if the input matches an item in the vector
		if (input == pRoom.getInventory()[i].getName())
		{
			cout << "You picked up the " << pRoom.getInventory()[i].getName() << endl;
			
			// Transfers the item from the room inventory to the player inventory
			pPlayer.setInventory(pRoom.getInventory()[i]);
			pPlayer.getInventory().pop_back();
			// This is the part I can't get to work because I'm trying to remove the item that was just
			// added to the player inventory from the room inventory
			// none of these methods work
			//pRoom.getInventory().erase(pRoom.getInventory().begin() + 0);
			//pRoom.getInventory().pop_back(i);
			//pRoom.getInventory().pop_back();
		}
		else
		{			
			cout << "You did not pick up the " << pRoom.getInventory()[i].getName() << endl;
		}
	}
}
//Checks if the exit exists in the room
void exits(Room pRoom)
{
	cout << "This room has an exit(s) in the " << pRoom.getExits() << endl;
}

//Get the input and determines which function to call per input getline
void getInput(Room pRoom, Character &pPlayer)
{
	string input;
	getline(cin, input);
	//converts the string to all lowercase
	transform(input.begin(), input.end(), input.begin(), (int(*)(int))tolower);

	if (input == "east" || input == "west" || input == "south" || input == "north")
	{
		checkExits(pRoom, input, pPlayer);
	}
	else if (input == "look")
	{
		pRoom.look(pRoom.getInventory());
	}
	// If the user enters the pickup command it will do this
	else if (input == "pickup")
	{
		cout << endl;
		cout << "What do you want to pick up?" << endl;
		// List the items that are currently in the room's inventory
		for (int i = 0; i < pRoom.getInventory().size(); ++i)
		{
			cout << pRoom.getInventory()[i].getName() << endl;
		}
		pickup(pRoom, pPlayer);
	}
	else if (input == "inventory")
	{
		//checks if the inventory 
		cout << "Your inventory contains: " << endl;
		for (int i = 0; i < pPlayer.getInventory().size(); i++)
		{
			cout << pPlayer.getInventory()[i].getName() << endl;
		}
	}
	//Calls the exits function
	else if (input == "exits")
	{
		exits(pRoom);
	}
	else if (input == "display")
	{
		showDisplay();
	}
	else
	{
		cout << endl;
		cout << input << " is an invalid command." << endl;
		cout << endl;
	}
}

//Moves the character based on the player, rooms and the input
void move(Character &player, Room &Room1, Room &Room2, Room &Room3, string input)
{
	if (player.getRoom() == 1)
	{
		// Gets input and compares it to the exits in the room
		getInput(Room1, player);
	}
	else if (player.getRoom() == 2)
	{
		// Gets input and compares it to the exits in the room
		getInput(Room2, player);
	}
	else if (player.getRoom() == 3)
	{
		// Gets input and compares it to the exits in the room
		getInput(Room3, player);
	}
}



int main()
{
	vector<Items>  playerItems;
	Character player;
	string input = "North";
	string start;

	// Room Declarations
	Room Room1("Room1", "Dark and Wet", "east");
	Room Room2("Room2", "Full of cobwebs", "south and west");
	Room Room3("Room3", "crumbling ceiling", "north");

	// Items declarations
	// Items for room 1
	Items sword("Sword", "Sharp", true, true, false, true, "Sword");
	Items shield("Shield", "A stirdy looking wood shield", false, true, false, true, "Shield");
	Room1.setInventory(sword);
	Room1.setInventory(shield);

	// Items for room 2
	Items key("Key", "Unlocks something", false, true, false, false, "Key");
	Room2.setInventory(key);

	// Items for room 3
	Items beer("Beer", "Gets you lit", false, true, false, false, "Beer");

	Enemy Jody("Jody", "a red headed Hellion", "If you let me out of this cage I will reward you.", 10);
	Jody.setInventory(beer);
	//creates the intro for the game
	cout << "******************************************************************************************" << endl;
	cout << "*          Welcome to Hell, CIS 244 edition: The never ending quest for beer!            *" << endl;
	cout << "* The object of the game is to find Jody and get beer off of him in any means necessary. *" << endl;
	cout << "* To win the game you must drink the beer that will then release you from being in Hell. *" << endl;
	cout << "*                              Enter any key to begin                                    *" << endl;
	cout << "******************************************************************************************" << endl;
	getline(cin, start);
	showDisplay();
	//Game loop based on if the beer is drank or not
	//and loops depending on which room you are in
	do
	{
		if (player.getRoom() == 1)
		{
			Room1.look(Room1.getInventory());
			do
			{
				cout << endl;
				cout << "What would you like to do?" << endl;
				move(player, Room1, Room2, Room3, input);
			} while (player.getRoom() == 1);
		}

		if (player.getRoom() == 2)
		{
			Room2.look(Room2.getInventory());
			do
			{
				cout << endl;
				cout << "What would you like to do?" << endl;
				move(player, Room1, Room2, Room3, input);
			} while (player.getRoom() == 2);
		}

		if (player.getRoom() == 3)
		{
			Room3.look(Room3.getInventory());
			jodyEncounter(player, Jody, beer);
			do
			{
				cout << endl;
				cout << "What would you like to do?" << endl;
				move(player, Room1, Room2, Room3, input);
			} while (player.getRoom() == 3);
		}
	} while (beer.getHasUsed() != true);


	cin.get();
	return 0;
}



