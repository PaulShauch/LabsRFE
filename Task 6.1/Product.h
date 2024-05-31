#pragma once
#include <iostream>

using namespace std;

class Product
{
protected:
	char* name;
	double price;
	static unsigned int balanceInStock;
public:
	Product(const char* name, double price);
	Product(const Product& product);
	Product& operator = (const Product& product);
	Product(Product&& product);
	Product& operator = (Product&& product);
	virtual ~Product();
	void SetName(const char* name);
	void SetPrice(double price);
	const char* GetName();
	const double GetPrice();
	virtual const unsigned int GetBalanceInStock();
	virtual void Print(ostream& out);
	friend ostream& operator << (ostream& out, Product& product);
};