#include <iostream>
#include <string>
#include <locale>
#include <fstream>
#include "myString.h"


int main()
{
	//open or create test log
	std::fstream fMyFile;
	fMyFile.open("TestLog.txt", std::ios::app);
	if (fMyFile.is_open())
	{
		std::cout << "The file was opened" << std::endl;
	}
	else
	{
		std::cout << "The file failed to open or could not be found" << std::endl;
	}

	//test strings
	std::string testStringA = "hello world";
	std::string testStringB = " this is me";
	std::string testStringC = "carrot";
	std::string testStringD = "o";
	myString MyString;

	fMyFile << "BEGIN TEST" << std::endl;
	//test 01 query the string’s length, returning an integer
	if (MyString.Length(testStringA) == testStringA.length())
	{
		fMyFile << "Test 01	String Length" << "\t\t\t" << "TEST SUCCESS" << std::endl;
	}
	else
	{
		fMyFile << "Test 01	String Length" << "\t\t\t" << "TEST FAIL" << std::endl;
	}
	//test 02 access a character at a certain index within the string class
	if (MyString.LocateChar(testStringA, 3) == 'l')
	{
		fMyFile << "Test 02	Locate Char at Index" << "\t\t" << "TEST SUCCESS" << std::endl;
	}
	else
	{
		fMyFile << "Test 02	Locate Char at Index" << "\t\t" << "TEST FAIL" << std::endl;
	}
	//test 03 compare if the string is the same as another string class
	if (MyString.Compare(testStringA, testStringB) == false)
	{
		fMyFile << "Test 03	Compare Strings" << "\t\t\t" << "TEST SUCCESS" << std::endl;
	}
	else
	{
		fMyFile << "Test 03	Compare Strings" << "\t\t\t" << "TEST FAIL" << std::endl;
	}
	//test 04 append one string to another
	if (MyString.Append(testStringA, testStringB) == "hello world this is me")
	{
		fMyFile << "Test 04	Append" << "\t\t\t\t" << "TEST SUCCESS" << std::endl;
	}
	else
	{
		fMyFile << "Test 04	Append" << "\t\t\t\t" << "TEST FAIL" << std::endl;
	}
	//test 05 prepend one string to another
	if (MyString.Prepend(testStringA, testStringB) == " this is mehello world")
	{
		fMyFile << "Test 05	Prepend" << "\t\t\t\t" << "TEST SUCCESS" << std::endl;
	}
	else
	{
		fMyFile << "Test 05	Prepend" << "\t\t\t\t" << "TEST FAIL" << std::endl;
	}
	//test 06 return the string as a basic constant C-style string (const char*)
	if (typeid(MyString.ConstChar(testStringA)) == typeid(const char*))
	{
		fMyFile << "Test 06	Const Char" << "\t\t\t" << "TEST SUCCESS" << std::endl;
	}
	else
	{
		fMyFile << "Test 06	Const Char" << "\t\t\t" << "TEST FAIL" << std::endl;
	}
	//test 07 convert the string to a duplicate containing all uppercase letters
	if(MyString.ToUpper(testStringA) == "HELLO WORLD")
	{
		fMyFile << "Test 07	To Uppercase" << "\t\t\t" << "TEST SUCCESS" << std::endl;
	}
	else
	{
		fMyFile << "Test 07	To Uppercase" << "\t\t\t" << "TEST FAIL" << std::endl;
	}
	//test 08 convert the string to a duplicate containing all lowercase letters
	if(MyString.ToLower(testStringA) == "hello world")
	{
		fMyFile << "Test 08	To Lowercase" << "\t\t\t" << "TEST SUCCESS" << std::endl;
	}
	else
	{
		fMyFile << "Test 08	To Lowercase" << "\t\t\t" << "TEST FAIL" << std::endl;
	}
	//test 09 find a sub-string within the string class
	if (MyString.FindSubstring(testStringA, testStringD) == true)
	{
		fMyFile << "Test 09	Find Substring" << "\t\t\t" << "TEST SUCCESS" << std::endl;
	}
	else
	{
		fMyFile << "Test 09 Find Substring" << "\t\t\t" << "TEST FAIL" << std::endl;
	}
	//test 10 find a sub-string within the string class, starting from a certain index within the string
	if (MyString.FindSubstringFrom(testStringA, testStringD, 10) == false)
	{
		fMyFile << "Test 10	Find Substring from Index" << "\t" << "TEST SUCCESS" << std::endl;
	}
	else
	{
		fMyFile << "Test 10 Find Substring from Index" << "\t" << "TEST FAIL" << std::endl;
	}
	//test 11 replace a sub-string found within the string with a different sub-string
	if (MyString.FindSubstringReplace(testStringA, testStringD, testStringC) == "hellcarrot wcarrotrld")
	{
		fMyFile << "Test 11	Find Substring and Replace" << "\t" << "TEST SUCCESS" << std::endl;
	}
	else
	{
		fMyFile << "Test 11 Find Substring and Replace" << "\t" << "TEST FAIL" << std::endl;
	}
	//test 12 set the string to an input C-style string
	if (typeid(MyString.ConvertCString(testStringA)) == typeid(char*))
	{
		fMyFile << "Test 12	Convert to C-Style String" << "\t" << "TEST SUCCESS" << std::endl;
	}
	else
	{
		fMyFile << "Test 12	Convert to C-Style String" << "\t" << "TEST FAIL" << std::endl;
	}

	system("pause");

	fMyFile << "END TEST" << std::endl;
	//close file
	if (fMyFile.is_open())
	{
		fMyFile.close();
		fMyFile.clear();
	}

	return 0;
}