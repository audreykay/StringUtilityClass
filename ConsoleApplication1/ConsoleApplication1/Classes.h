#pragma once
#ifndef _CLASSES_H_
#define _CLASSES_H_
//Base Location Class
class Location
{
public:
	Location();
	~Location();

protected:
	
};
//Room Class inherited from Location
//Supply, HallA, HallB, Cat, Box, Parrot, Foyer
class Room : public Location
{
public:
	bool bActive = false;
	const char* filename;
	void DisplayDescription();
	
protected:
	
};
//Container Class inherited from Room
//Trash, Parrot, LockBox, Mac, Cat
class Container : public Room
{
public:
	bool bContainsItem = true;

protected:

};

//inventory class
class Inventory
{
public:
	Inventory();
	~Inventory();
	bool bMirror = false;
	bool bKey = false;
	bool bIdCard = false;
	bool bKitten = false;

private:

};


#endif