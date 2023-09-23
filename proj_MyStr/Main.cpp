#include <iostream>
#include "MyStr.h"
using namespace std;

unsigned int MyString::s_count = 0;

int main()
{
	MyString str("Hello");
	cout << str;

	cout << "\nobj + 'A'" << endl;
	str = str + 'A';
	cout << str;

	cout << "\n'A' + obj" << endl;
	str = 'A' + str;
	cout << str;

	cout << "\n++obj" << endl;
	++str;
	cout << str;
	cout << "\nobj++" << endl;
	str++;
	cout << str;

	cout << "\n!obj + 10" << endl;
	str = str + 10;
	cout << str;

	cout << "\n!obj + 10" << endl;
	str = 10 + str;
	cout << str;

	/*MyString str1("Hello ");
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

	cout << "\nNumber of strings created: " << MyString::getStatic()<<endl;*/

	/*cout << "\nobj + 'A'" << endl;
	MyString str4("Hello");
	MyString res = str4 + 'A';
	res.PrintStr();

	cout << "\n'A' + obj" << endl;
	MyString str5("Hello");
	MyString res1 = 'A'+ str5;
	res1.PrintStr();

	MyString strA("Hello");
	cout << strA ;*/

}