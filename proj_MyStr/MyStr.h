#pragma once
#include <iostream>
using namespace std;
class MyString
{
private:
	char* str;
	int length;
	static unsigned int s_count;
public:
	void delNullPtr(char* pointer);
	MyString();
	MyString(const char* userStr);
	MyString(const MyString& point);
	~MyString();

	void PrintStr();
	void InputStr();

	void MyStrCpy(MyString& obj);
	void MyStrCpy(const char* userStr);
	bool MyStrStr(const char* str);
	int MyChr(char c);
	int MyStrLen(const char* userStr);
	void MyStrCat(MyString& b); 
	void MyDelChr(char c);
	int MyStrCmp(MyString& b);

	static void incrStatic();
	static int getStatic();

	char* GetStr() const;
	int GetLength() const;

	MyString& operator++();
	MyString& operator++(int);

	char& operator[](const unsigned int index);
	void operator()();

	MyString& operator=(const MyString& obj);

	MyString& operator=(MyString&& point);
	MyString(MyString&& obj);

};
MyString operator+(const MyString obj, const char ch);
MyString operator+(const char ch, const MyString obj);
MyString operator+(MyString obj, int n);
MyString operator+(int n, MyString obj);
ostream& operator<<(ostream& os, const MyString& obj);
istream& operator>>(istream& is, MyString& obj);
