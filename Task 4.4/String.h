#pragma once

using namespace std;

class String
{
	friend istream& operator >> (istream&, String&);
	friend ostream& operator << (ostream&, String&);
private:
	char* array;
	int size;
public:
	String();
	String(const char*);
	~String();
	String(const String& string);
	String& operator = (const String& string);
	String(String&& string);
	String& operator = (String&& string);
	String& operator + (String& string);
	void replace (String& oldpodstr, String& newpodstr);
};