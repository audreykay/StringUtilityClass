#include <iostream>
#include <string>
#include <locale>
#include <fstream>
#include "Classes.h"
#include "MyString.h"

//set up inventory
Inventory Inv;

//set up command inputs
MyString string;
std::string command;
std::string& commandRef = command;
std::string moveNorth = "move north";
std::string moveSouth = "move south";
std::string moveEast = "move east";
std::string moveWest = "move west";
//game states
bool bGameStart = true;
bool bGameOn = false;
bool bGameOver = false;
//display menu
void displayMenu()
{
	system("cls");

	std::fstream fMyFile;

	fMyFile.open("Menu.txt", std::ios::in);
	if (fMyFile.is_open())
	{
		std::cout << fMyFile.rdbuf();
		fMyFile.close();
		fMyFile.clear();
	}
	system("pause");
}
//inventory display
void displayInventory()
{
	system("cls");
	
	std::cout << "INVENTORY" << std::endl;

	if (Inv.bMirror == false
		&& Inv.bKey == false
		&& Inv.bKitten == false
		&& Inv.bIdCard ==false)
	{
		std::cout << "Your inventory is empty." << std::endl;
	}
	else
	{
		if (Inv.bMirror == true)
		{
			std::cout << "Mirror" << std::endl;
		}
		if (Inv.bKey == true)
		{
			std::cout << "Key" << std::endl;
		}
		if (Inv.bKitten == true)
		{
			std::cout << "Kitten" << std::endl;
		}
		if (Inv.bIdCard == true)
		{
			std::cout << "ID Card" << std::endl;
		}
	}
	std::cout << std::endl;
	system("pause");
	
}
//get user input
std::string GetInput()
{
	std::cout << ">> ";
	std::getline(std::cin, commandRef);
	string.ToLower(commandRef);
	return commandRef;
}

//main function
int main()
{
	//set up the game	
	Room SupplyRoom;
	SupplyRoom.filename = "SupplyRoom.txt";
	Room HallA;
	HallA.filename = "HallwayA.txt";
	Room HallB;
	HallB.filename = "HallwayB.txt";
	Room BoxRoom;
	BoxRoom.filename = "BoxRoom.txt";
	Room CatRoom;
	CatRoom.filename = "CatRoom.txt";
	Room ParrotRoom;
	ParrotRoom.filename = "ParrotRoom.txt";
	Room Foyer;
	Foyer.filename = "Foyer.txt";
	//set up the interactive objects
	Container Parrot;
	if (Parrot.bContainsItem == true)
	{
		Parrot.filename = "Parrot.txt";
	}
	else
	{
		Parrot.filename = "ParrotEmpty.txt";
	}
	Container Cat;
	if (Cat.bContainsItem == true)
	{
		Cat.filename = "Cat.txt";
	}
	else
	{
		Cat.filename = "CatEmpty.txt";
	}
	Container Box;
	if (Box.bContainsItem == true)
	{
		Box.filename = "Box.txt";
	}
	else
	{
		Box.filename = "BoxEmpty.txt";
	}
	Container Trash;
	if (Trash.bContainsItem == true)
	{
		Trash.filename = "Trash.txt";
	}
	else
	{
		Trash.filename = "TrashEmpty.txt";
	}
	Container Computer;
	if (Computer.bContainsItem == true)
	{
		Computer.filename = "Computer.txt";
	}
	else
	{
		Computer.filename = "ComputerEmpty.txt";
	}

	if (bGameStart == true)
	{
		system("cls");

		std::fstream fMyFile;

		fMyFile.open("Opening.txt", std::ios::in);
		if (fMyFile.is_open())
		{
			std::cout << fMyFile.rdbuf();
			fMyFile.close();
			fMyFile.clear();
		}
		system("pause");
		displayMenu();
		bGameStart = false;
		SupplyRoom.bActive = true;
		bGameOn = true;
	}
	//START IN SUPPLY ROOM
	
	//START GAME LOOP
	while (bGameOn == true)
	{
		//while games active MENU, INV, INSTRUCTIONS
		
		//SUPPLY ROOM
		while (SupplyRoom.bActive == true)
		{
			system("cls");
			SupplyRoom.DisplayDescription();
			GetInput();
			//can only go NORTH in supply room
			if (command == moveNorth)
			{
				SupplyRoom.bActive = false;
				HallA.bActive = true;
			}	
			else if (command == "inv")
			{
				displayInventory();
			}
			else if (command == "menu")
			{
				displayMenu();
			}
			else 
			{
				std::cout << "Sorry, I didn't understand that." << std::endl;
				system("pause");
			}
		
		}
		//if HALL A active
		while (HallA.bActive == true)
		{
			system("cls");
			HallA.DisplayDescription();
			GetInput();
			//can go NORTH, SOUTH, WEST in HallA & trash
			if (command == moveNorth)
			{
				HallA.bActive = false;
				CatRoom.bActive = true;
			}
			else if (command == moveSouth)
			{
				HallA.bActive = false;
				SupplyRoom.bActive = true;
			}
			else if (command == moveWest)
			{
				HallA.bActive = false;
				HallB.bActive = true;
			}
			else if (command == "look trash")
			{
				HallA.bActive = false;
				Trash.bActive = true;
			}
			else if (command == "inv")
			{
				displayInventory();
			}
			else if (command == "menu")
			{
				displayMenu();
			}
			else
			{
				std::cout << "Sorry, I didn't understand that." << std::endl;
				system("pause");
			}
		}
		//while HALLB active
		while (HallB.bActive == true)
		{
			system("cls");
			HallB.DisplayDescription();
			GetInput();
			//can go N, S, E, W
			if (command == moveNorth)
			{
				HallB.bActive = false;
				BoxRoom.bActive = true;
			}
			else if (command == moveSouth)
			{
				HallB.bActive = false;
				ParrotRoom.bActive = true;
			}
			else if (command == moveEast)
			{
				HallB.bActive = false;
				HallA.bActive = true;
			}
			else if (command == moveWest)
			{
				HallB.bActive = false;
				Foyer.bActive = true;
			}
			else if (command == "inv")
			{
				displayInventory();
			}
			else if (command == "menu")
			{
				displayMenu();
			}
			else
			{
				std::cout << "Sorry, I didn't understand that." << std::endl;
				system("pause");
			}
		}
		//while in CAT ROOM
		while (CatRoom.bActive == true)
		{
			system("cls");
			CatRoom.DisplayDescription();
			GetInput();
			//can only go S and cat
			if (command == "look cat")
			{
				CatRoom.bActive = false;
				Cat.bActive = true;
			}
			else if (command == moveSouth)
			{
				CatRoom.bActive = false;
				HallA.bActive = true;
			}
			else if (command == "inv")
			{
				displayInventory();
			}
			else if (command == "menu")
			{
				displayMenu();
			}
			else
			{
				std::cout << "Sorry, I didn't understand that." << std::endl;
				system("pause");
			}
		}
		//while in BOX ROOM
		while (BoxRoom.bActive == true)
		{
			system("cls");
			BoxRoom.DisplayDescription();
			GetInput();
			//can only go S and box
			if (command == "look box")
			{
				BoxRoom.bActive = false;
				Box.bActive = true;
			}
			else if (command == moveSouth)
			{
				BoxRoom.bActive = false;
				HallB.bActive = true;
			}
			else if (command == "inv")
			{
				displayInventory();
			}
			else if (command == "menu")
			{
				displayMenu();
			}
			else
			{
				std::cout << "Sorry, I didn't understand that." << std::endl;
				system("pause");
			}
		}
		//while in PARROT ROOM
		while (ParrotRoom.bActive == true)
		{
			system("cls");
			ParrotRoom.DisplayDescription();
			GetInput();
			//can only go N and PARROT
			if (command == moveNorth)
			{
				ParrotRoom.bActive = false;
				HallB.bActive = true;
			}
			else if (command == "look parrot")
			{
				ParrotRoom.bActive = false;
				Parrot.bActive = true;
			}
			else if (command == "inv")
			{
				displayInventory();
			}
			else if (command == "menu")
			{
				displayMenu();
			}
			else
			{
				std::cout << "Sorry, I didn't understand that." << std::endl;
				system("pause");
			}
			

		}
		//while in FOYER
		while (Foyer.bActive == true)
		{
			system("cls");
			Foyer.DisplayDescription();
			GetInput();
			//only go E, comp, exit
			if (command == "look computer")
			{
				Foyer.bActive = false;
				Computer.bActive = true;
			}
			else if (command == moveEast)
			{
				Foyer.bActive = false;
				HallB.bActive = true;
			}
			else if (command == "inv")
			{
				displayInventory();
			}
			else if (command == "menu")
			{
				displayMenu();
			}
			else
			{
				std::cout << "Sorry, I didn't understand that." << std::endl;
				system("pause");
			}
		}

		//containers trash cat parrot box
		while (Trash.bActive == true)
		{
			system("cls");
			Trash.DisplayDescription();
			GetInput();
			//interact with mirror, walk north south west
			if (command == "use mirror" || 
				command == "get mirror" ||
				command == "look mirror")
			{
				system("cls");
				std::cout << "You pick up the MIRROR. It is now in your INV." << std::endl;
				system("pause");
				Trash.bContainsItem = false;
				Trash.filename = "TrashEmpty.txt";
				Inv.bMirror = true;
			}
			else if (command == moveNorth)
			{
				Trash.bActive = false;
				CatRoom.bActive = true;
			}
			else if (command == moveSouth)
			{
				Trash.bActive = false;
				SupplyRoom.bActive = true;
			}
			else if (command == moveWest)
			{
				Trash.bActive = false;
				HallB.bActive = true;
			}
			else if (command == "inv")
			{
				displayInventory();
			}
			else if (command == "menu")
			{
				displayMenu();
			}
			else
			{
				std::cout << "Sorry, I didn't understand that." << std::endl;
				system("pause");
			}
		}
		//while PARROT active
		while (Parrot.bActive == true)
		{
			system("cls");
			Parrot.DisplayDescription();
			GetInput();
			//can only move north and interact with parrot
			if (Parrot.bContainsItem == true &&
				command == "use mirror")
			{
				system("cls");
				std::cout << "You give the MIRROR to the PARROT. He is particularly enamoured with his reflection. The brass KEY clatters to the floor. You decide to keep the KEY. The KEY is now in your INV." << std::endl;
				system("pause");
				Inv.bMirror = false;
				Parrot.bContainsItem = false;
				Parrot.filename = "ParrotEmpty.txt";
				Inv.bKey = true;
			}
			else if (command == moveNorth)
			{
				Parrot.bActive = false;
				HallB.bActive = true;
			}
			else if (command == "inv")
			{
				displayInventory();
			}
			else if (command == "menu")
			{
				displayMenu();
			}
			else
			{
				std::cout << "Sorry, I didn't understand that." << std::endl;
				system("pause");
			}
		}
		//while BOX active
		while (Box.bActive == true)
		{
			system("cls");
			Box.DisplayDescription();
			GetInput();
			//open box, move south
			if (Box.bContainsItem == true && command == "use key")
			{
				system("cls");
				std::cout << "You use the KEY in the keyhole. It fits perfectly. As you feel the lock click open, the KEY disintegrates in your hand. The BOX swings open. There is a small KITTEN in the box. You decide to take it. The KITTEN is now in your INV." << std::endl;
				system("pause");
				Inv.bKey = false;
				Box.bContainsItem = false;
				Box.filename = "BoxEmpty.txt";
				Inv.bKitten = true;
			}
			else if (command == moveSouth)
			{
				Box.bActive = false;
				HallB.bActive = true;
			}
			else if (command == "inv")
			{
				displayInventory();
			}
			else if (command == "menu")
			{
				displayMenu();
			}
			else
			{
				std::cout << "Sorry, I didn't understand that." << std::endl;
				system("pause");
			}
		}
		//WHILE CAT ACTIVE
		while (Cat.bActive == true)
		{
			system("cls");
			Cat.DisplayDescription();
			GetInput();
			//move south, give cat kitten
			if (Cat.bContainsItem == true && 
				command == "use kitten")
			{
				system("cls");
				std::cout << "You pull the KITTEN out of your INV. The CAT immediately ceases screaming. You slowly place the KITTEN next to the CAT. The CAT gets up and moves to the KITTEN, giggling intensely." << std::endl;
				std::cout << "There is an ID CARD where the CAT used to be. You decide to keep it. The ID CARD is now in your INV." << std::endl;
				system("pause");
				Inv.bKitten = false;
				Cat.bContainsItem = false;
				Cat.filename = "CatEmpty.txt";
				Inv.bIdCard = true;
			}
			else if (command == moveSouth)
			{
				Cat.bActive = false;
				HallA.bActive = true;
			}
			else if (command == "inv")
			{
				displayInventory();
			}
			else if (command == "menu")
			{
				displayMenu();
			}
			else
			{
				std::cout << "Sorry, I didn't understand that." << std::endl;
				system("pause");
			}
		}
		while (Computer.bActive == true)
		{
			system("cls");
			Computer.DisplayDescription();
			GetInput();
			//move south, give cat kitten
			if (Computer.bContainsItem == true &&
				command == "use id card" ||
				command == "use idcard")
			{
				system("cls");
				std::cout << "You swipe the ID CARD. The COMPUTER switches to the login screen." << std::endl;
				system("pause");
				Computer.bContainsItem = false;
				Computer.filename = "ComputerEmpty.txt";
			}
			else if (command == moveEast)
			{
				Computer.bActive = false;
				HallB.bActive = true;
			}
			else if (command == "inv")
			{
				displayInventory();
			}
			else if (command == "menu")
			{
				displayMenu();
			}
			else if (Computer.bContainsItem == false &&
				command == "error")
			{
				//uwin
				system("cls");
				std::cout << "You heave a sigh of relief as the computer boots up, and the only application \"DOOR UNLOCK\" becomes available. You double click with anticipation. Slowly, but surely, the automatic glass doors slide open and you are finally free to go HOME." << std::endl;
				system("pause");
				Computer.bActive = false;
				bGameOn = false;
				//return 0;
				bGameOver = true;
			}
			else
			{
				std::cout << "Sorry, I didn't understand that." << std::endl;
				system("pause");
			}
		}
		while (bGameOver == true)
		{
			system("cls");
			std::fstream fMyFile;
			fMyFile.open("Closing.txt", std::ios::in);
			if (fMyFile.is_open())
			{
				std::cout << fMyFile.rdbuf();
				fMyFile.close();
				fMyFile.clear();
			}
			system("pause");
			return 0;
		}
	}
	
	return 0;
}