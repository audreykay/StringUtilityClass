#pragma once
#ifndef _SOURCE_H_
#define _SOURCE_H_


class myString
{
public:
	myString(); //constructor
	~myString(); //deconstructor

	//public data / functions
	int Length(std::string strA); //find length/size of string
	char LocateChar(std::string strA, int i); //access char at certain index
	bool Compare(std::string strA, std::string strB); //compare strings
	std::string Append(std::string strA, std::string strB); //append B to A
	std::string Prepend(std::string strA, std::string strB); //prepend B to A
	const char* ConstChar(std::string strA); //convert from string to const char*
	std::string ToUpper(std::string& strA); //convert string to upper case
	std::string ToLower(std::string& strA); //convert to lowercase
	bool FindSubstring(std::string strA, std::string strB); //find substring in string
	bool FindSubstringFrom(std::string strA, std::string strB, int i); //find substring from index #
	std::string FindSubstringReplace(std::string& strA, std::string strB, std::string strC); //find and replace a substring with another substring
	char* ConvertCString(std::string strA); //convert to c style string

private:
	// private data
	

};


#endif
