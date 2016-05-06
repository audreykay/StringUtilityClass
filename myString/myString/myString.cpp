#include <iostream>
#include <string>
#include <locale>
#include "myString.h"

myString::myString()
{

}

myString::~myString()
{

}

//find length of string
int myString::Length(std::string strA)
{
	return strA.length();
}

//access char at particular index
char myString::LocateChar(std::string strA, int i)
{
	//char a = str.at(i);
	//return (char)a;
	return strA.at(i);
}

//compare two strings
bool myString::Compare(std::string strA, std::string strB)
{
	bool identicalStrings;
	if (strA.compare(strB) != 0)
	{
		//std::cout << "Not the same!";
		identicalStrings = false;
	}
	else
	{
		//std::cout << "the same!";
		identicalStrings = true;
	}
	return identicalStrings;
}

//append a string to string
std::string myString::Append(std::string strA, std::string strB)
{
	strA.append(strB);
	return strA;
}

//prepend a string to string
std::string myString::Prepend(std::string strA, std::string strB)
{
	strA.insert(0, strB);
	return strA;
}

//convert string to const char
const char* myString::ConstChar(std::string strA)
{
	//const char * c = strA.c_str();
	return strA.c_str();
}

//convert string to upper case
std::string myString::ToUpper(std::string& strA)
{
	for (std::string::size_type i = 0; i < strA.length(); ++i)
		strA.at(i) = toupper(strA.at(i));
	return strA;
}

//convert to lower case
std::string myString::ToLower(std::string& strA)
{
	for (std::string::size_type i = 0; i < strA.length(); ++i)
		strA.at(i) = tolower(strA.at(i));
	return strA;
}

//find a substring
bool myString::FindSubstring(std::string strA, std::string strB)
{
	bool substring;
	std::size_t found = strA.find(strB);
	if (found != std::string::npos)
		substring = true;
	else
		substring = false;
	return substring;
}

//find substring from index #
bool myString::FindSubstringFrom(std::string strA, std::string strB, int i) 
{
	bool substring;
	std::size_t found = strA.find(strB,i);
	if (found != std::string::npos)
		substring = true;
	else
		substring = false;
	return substring;

}

//find substring and replace
std::string myString::FindSubstringReplace(std::string& strA, std::string strB, std::string strC)
{
	size_t pos = 0;
	while ((pos = strA.find(strB, pos)) != std::string::npos)
	{
		strA.replace(pos, strB.length(), strC);
		pos += strC.length();
	}
	return strA;
}

//convert to c string
char* myString::ConvertCString(std::string strA)
{
	char * cstrA = new char[strA.length() + 1];
	std::strcpy(cstrA, strA.c_str());
	return cstrA;
}

int function()
{
	int i = 0;
	myString MyString;
	std::string string1;
	std::string string2;
	std::string string3;
	std::cout << "String One: ";
	std::getline(std::cin, string1);
	//std::cin.ignore();
	std::cout << "String Two: ";
	std::getline(std::cin, string2);
	//std::cout << "Index number: ";
	//std::cin >> i;
	std::cout << "String Three: ";
	std::getline(std::cin, string3);

	
	
	MyString.FindSubstringReplace(string1, string2, string3);
	std::cout << string1;
/*
	//string length, use getline instead of cin for more than first word
	std::cout << "Enter a stringaling: ";
	std::getline(std::cin, stringInput);
	std::cout << stringOne.Length(stringInput);
	//access char at index
	int strAccess;
	std::cout << "Which index would you like to access (numerical): ";
	std::cin >> strAccess;
	std::cout << stringOne.accessChar(stringInput, strAccess);
	//compare the two
	std::cin.ignore();
	std::cout << "Another stringaling!: ";
	std::getline(std::cin, string2);
	stringOne.stringCompare(stringInput, string2);
	//append A to B
	std::cout << stringOne.stringAppend(stringInput, string2);
	//prepend B to A
	std::cout << stringOne.stringPrepend(stringInput, string2);
	//convert to const char
	stringOne.stringCConversion(string2);
	//convert to uppercase
	stringOne.stringToUpper(stringInput);
	//convert to lowercase
	stringOne.stringToLower(stringInput);
	//search for substring in string
	stringOne.stringSub(stringInput, string2);
	//search for substring in string from index #
	stringOne.stringSubIndex(stringInput, string2, i);
	//find substring in string and replace with different substring
	stringOne.stringSubAndReplace(string1, string2, string3);
*/
	system("pause");
	return 0;
}
