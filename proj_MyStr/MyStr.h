#pragma once
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

};