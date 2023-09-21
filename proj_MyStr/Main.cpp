#include <iostream>
#include "MyStr.h"
using namespace std;

unsigned int MyString::s_count = 0;

int main()
{
	MyString str1("Hello ");
	MyString str2("world");

	cout << "Str1: ";
	str1.PrintStr();
	cout << "Str2: ";
	str2.PrintStr();

	MyString str3;
	str3.InputStr();
	cout << "Output: ";
	str3.PrintStr();

	int result = str1.MyStrCmp(str2);
	cout <<"\nComparing two strings: "<< result << endl;

	cout << "\nSearching for a substring: ";
	MyString mainStr("Hello, world!");
	const char* subStr = "world";
	cout << mainStr.MyStrStr(subStr)<<endl;

	cout << "\nSearching for a char index: ";
	cout << str1.MyChr('l') << endl;

	cout << "\nConcatenation: ";
	str1.MyStrCat(str2);
	str1.PrintStr();

	cout << "\nDeleting char: "<<endl;
	MyString strDelChar("Jack decided to add red apples to his daily diet.");
	strDelChar.MyDelChr('d');
	strDelChar.PrintStr();

	cout << "\nNumber of strings created: " << MyString::getStatic();
}