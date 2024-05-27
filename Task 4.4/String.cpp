#include <iostream>
#include "String.h"

using namespace std;

String::String()
{
	this->array = new char[0];
	this->size = 0;
}

String::String(const char* str)
{
	int len = strlen(str);
	this->size = len;
	this->array = new char[len];
	for (int i = 0; i < len; i++)
	{
		this->array[i] = str[i];
	}
}

String::~String()
{
	delete[] this->array;
	this->size = 0;
}

String::String(const String& string)
{
	this->size = string.size;
	this->array = new char[size];
	for (int i = 0; i < size; i++)
	{
		this->array[i] = string.array[i];
	}
}

String& String::operator = (const String& string)
{
	this->size = string.size;
	this->array = new char[size];
	for (int i = 0; i < size; i++)
	{
		this->array[i] = string.array[i];
	}
	return *this;
}

String::String(String&& string)
{
	this->size = string.size;
	this->array = new char[size];
	for (int i = 0; i < size; i++)
	{
		this->array[i] = string.array[i];
	}
	string.size = 0;
	delete[] string.array;
}

String& String::operator = (String&& string)
{
	this->size = string.size;
	this->array = new char[size];
	for (int i = 0; i < size; i++)
	{
		this->array[i] = string.array[i];
	}
	string.size = 0;
	delete[] string.array;
	return *this;
}

istream& operator >> (istream& in, String& string)
{
	int N = 100;
	char* arr = new char[N];
	in.getline(arr, N);
	N = strlen(arr);
	string.array = new char[N];
	for (int i = 0; i < N; i++)
	{
		string.array[i] = arr[i];
	}
	string.size = N;
	return in;
}

ostream& operator << (ostream& out, String& string)
{
	for (int i = 0; i < string.size; i++)
	{
		out << string.array[i];
	}
	out << endl;
	return out;
}

String& String::operator + (String& string)
{
	char* newArr = new char[this->size + string.size + 1];
	int i = 0;
	for (; i < this->size; i++)
	{
		newArr[i] = this->array[i];
	}
	for (; i < this->size + string.size; i++)
	{
		newArr[i] = string.array[i - this->size];
	}
	newArr[this->size + string.size] = '\0';
	String newString(newArr);
	String* newStr = new String;
	newStr->array = newArr;
	newStr->size = this->size + string.size;
	return *newStr;
}

void String::replace (String& oldpodstr, String& newpodstr)
{
	int i = 0;
	int j = 0;
	while (i < this->size)
	{
		while (oldpodstr.array[j] != this->array[i])
		{
			if (j >= oldpodstr.size || i >= this->size)
			{
				return;
			}
			i++;
		}
		while (oldpodstr.array[j] == this->array[i] && j < oldpodstr.size && i < this->size)
		{
			i++;
			j++;
		}
		if (oldpodstr.array[j - 1] == this->array[i - 1] && j == oldpodstr.size)
		{
			int l = i;
			i -= oldpodstr.size;
			j = 0;
			char* arr = new char[this->size - oldpodstr.size + newpodstr.size];
			for (int k = 0; k < i; k++)
			{
				arr[k] = this->array[k];
			}
			for (int k = 0; k < newpodstr.size; k++, i++)
			{
				arr[i] = newpodstr.array[k];
			}
			int m = i;
			while (l < this->size)
			{
				arr[i] = this->array[l];
				l++;
				i++;
			}
			this->size = this->size - oldpodstr.size + newpodstr.size;
			this->array = arr;
			j = 0;
			i = m - 1;
		}
		i++;
	}
}