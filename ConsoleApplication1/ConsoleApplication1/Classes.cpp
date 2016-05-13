#include <iostream>
#include <string>
#include <locale>
#include <fstream>
#include "Classes.h"

Location::Location()
{

}

Location::~Location()
{

}

void Room::DisplayDescription()
{
	
	std::fstream fMyFile;

	fMyFile.open(filename, std::ios::in);
	if (fMyFile.is_open())
	{
		std::cout << fMyFile.rdbuf();
		fMyFile.close();
		fMyFile.clear();
	}

}

Inventory::Inventory()
{

}

Inventory::~Inventory()
{

}