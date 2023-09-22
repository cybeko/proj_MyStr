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
MyString& MyString::operator=(const MyString& obj)
{
	if (this != &obj)
	{
		delete[] str;
		length = obj.length;
		str = new char[length];
		for (int i = 0; i < length; ++i)
		{
			str[i] = obj.str[i];
		}
	}
	return *this;
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
MyString operator+(const MyString obj, const char ch)
{
	int strLen = obj.GetLength();

	char* newStr = new char[strLen + 2];
	for (int i = 0; i < strLen -1; i++)
	{
		newStr[i] = obj.GetStr()[i];
	}
	newStr[strLen -1] = ch;
	newStr[strLen] = '\0';
	return MyString(newStr);
}
MyString operator+(const char ch, const MyString obj)
{
	int strLen = obj.GetLength();

	char* newStr = new char[strLen + 2];

	newStr[0] = ch;
	for (int i = 1; i <= strLen; i++)
	{
		newStr[i] = obj.GetStr()[i-1];
	}
	newStr[strLen] = '\0';
	return MyString(newStr);
}
MyString operator+(MyString obj, int n)
{
	int oldLen = obj.GetLength();
	char* oldStr = obj.GetStr();

	int newLen = oldLen + n;
	char* newStr = new char[newLen];

	for (int i = 0; i < newLen; i++)
	{
		if (i < oldLen - 1)
		{
			newStr[i] = oldStr[i];
		}
		else
		{
			newStr[i] = '^';
		}
	}
	newStr[newLen - 1] = '\0';
	MyString tempStr(newStr);
	return tempStr;
}
MyString operator+(int n, MyString obj)
{
	int oldLen = obj.GetLength();
	char* oldStr = obj.GetStr();

	int newLen = oldLen + n;
	char* newStr = new char[newLen];
	int j = 0;
	for (int i = 0; i < newLen; i++)
	{
		if (i < n)
		{
			newStr[i] = '^';
		}
		else
		{
			newStr[i] = oldStr[j];
			j++;
		}
	}
	newStr[newLen - 1] = '\0';
	MyString tempStr(newStr);
	return tempStr;
}
char* MyString::GetStr() const
{
	return str;
}
int MyString::GetLength() const
{
	return length;
}
MyString& MyString::operator++()
{
	char* newStr = new char[length+1];
	newStr[0] = '_';
	for (int i = 0; i < length; i++)
	{
		newStr[i + 1] = str[i];
	}
	delete[] str;
	str = newStr;
	return *this;
}
MyString& MyString::operator++(int)
{
	char* newStr = new char[length+2];
	for (int i = 0; i < length; i++)
	{
		newStr[i] = str[i];
	}
	newStr[length] = '_';
	newStr[length+1] = '\0';
	delete[] str;
	str = newStr;
	return *this;
}
ostream& operator<<(ostream& os, const MyString& obj)
{
	os << obj.GetStr() << endl;
	//os << obj.GetLength() << endl;
	return os;
}
istream& operator>>(istream& is, MyString& obj)
{
	char buff[100];
	cin.getline(buff, sizeof(buff));
	obj.MyStrCpy(buff);
	return is;
}
char& MyString::operator[](const unsigned int id)
{
	if (id >= 0 && id <= length)
	{
		return str[id];
	}
	return str[0];
}
void MyString::operator()()
{
	this->InputStr();
	this->PrintStr();
}
