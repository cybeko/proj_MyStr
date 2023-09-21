#include "MyStr.h"
#include <iostream>
using namespace std;

MyString::MyString()
{
	//cout << "[Constructor]" << endl;
	str = nullptr;
	length = 0;
	incrStatic();
}
MyString::MyString(const char* userStr)
{
	//cout << "[Constructor]" << endl;
	length = MyStrLen(userStr) + 1;
	str = new char[length];
	for (int i = 0; i < length; i++)
	{
		str[i] = userStr[i];
	}
	incrStatic();
}
MyString::MyString(const MyString& point)
{
	length = point.length;
	str = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		str[i] = point.str[i];
	}
	incrStatic();
}
void MyString::delNullPtr(char* pointer)
{
	delete[] pointer;
	pointer = nullptr;
}
MyString::~MyString()
{
	//cout << "[Destructor]" << endl;
	delete[] str;
}
void MyString::MyStrCpy(const char* userStr)
{
	//cout << "[Copy constructor]" << endl;
	delNullPtr(str);
	length = MyStrLen(userStr) + 1;
	str = new char[length];
	for (int i = 0; i < length; i++)
	{
		str[i] = userStr[i];
	}
}
void MyString::MyStrCpy(MyString& obj)
{
	//cout << "[Copy constructor]" << endl;
	delNullPtr(str);
	length = obj.length;
	str = new char[length];
	for (int i = 0; i < length; i++)
	{
		str[i] = obj.str[i];
	}
}
bool MyString::MyStrStr(const char* userStr)
{
	if (str == nullptr || userStr == nullptr)
	{
		return false;
	}
	int strLen = MyStrLen(str);
	int subStrLen = MyStrLen(userStr);
	if (subStrLen == 0)
	{
		return true;
	}
	for (int i = 0; i <= strLen - subStrLen; i++)
	{
		bool found = true;

		for (int j = 0; j < subStrLen; j++)
		{
			if (str[i + j] != userStr[j])
			{
				found = false;
				break;
			}
		}
		if (found)
		{
			return true;
		}
	}
	return false;
}
int MyString::MyStrCmp(MyString& b)
{
	if (str == nullptr && b.str == nullptr)
	{
		return 0;
	}
	else if (str == nullptr)
	{
		return -1;
	}
	else if (b.str == nullptr)
	{
		return 1;
	}
	int i = 0;
	while (str[i] != '\0' && b.str[i] != '\0')
	{
		if (str[i] < b.str[i])
		{
			return -1;
		}
		else if (str[i] > b.str[i])
		{
			return 1;
		}
		i++;
	}
}
void MyString::incrStatic()
{
	MyString::s_count++;
}
int MyString::getStatic()
{
	return MyString::s_count++;;
}
void MyString::InputStr()
{
	char buff[80];
	cout << "\nInput string: ";
	cin.getline(buff, sizeof(buff));
	MyStrCpy(buff);
}
void MyString::PrintStr()
{
	if (str == nullptr)
	{
		cout << "nullptr" << endl;
	}
	else
	{
		cout << str << endl;
	}
}
int MyString::MyChr(char c)
{
	if (str == nullptr)
	{
		return -1;
	}
	int strLen = MyStrLen(str);

	for (int i = 0; i < strLen; i++)
	{
		if (str[i] == c)
		{
			return i;
		}
	}
	return -1;
}
int MyString::MyStrLen(const char* userStr)
{
	int i = 0;
	while (userStr[i] != '\0')
	{
		i++;
	}
	return i;
}

void MyString::MyStrCat(MyString& b)
{
	int strLen = MyStrLen(str);
	int strLen_b = MyStrLen(b.str);
	int newLen = strLen + strLen_b;

	char* newStr = new char[newLen + 1];
	int id = 0;
	for (int i = 0; i < strLen; i++)
	{
		newStr[i] = str[i];
	}
	for (int i = 0; i < strLen_b; i++)
	{
		newStr[strLen + i] = b.str[i];
	}
	newStr[newLen] = '\0';

	delete[] str;
	str = newStr;
	length = newLen;
}

void MyString::MyDelChr(char c)
{
	if (str == nullptr)
	{
		return;
	}

	int strLen = MyStrLen(str);
	char* newStr = new char[strLen + 1];
	int newLen = 0;

	for (int i = 0; i < strLen; i++)
	{
		if (str[i] != c)
		{
			newStr[newLen] = str[i];
			newLen++;
		}
	}
	newStr[newLen] = '\0';
	delete[] str;
	str = newStr;
	length = newLen;
}
//+ ch
MyString operator+(const MyString obj, const char ch)
{
	int strLen = obj.length;

	char* newStr = new char[strLen + 2];
	for (int i = 0; i < strLen -1; i++)
	{
		newStr[i] = obj.str[i];
	}
	newStr[strLen -1] = ch;
	newStr[strLen] = '\0';
	return MyString(newStr);
}
const char* MyString::GetStr()
{
	return str;
}