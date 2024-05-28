#include "Product.h"
#include <iostream>

using namespace std;

Product::Product(const char* name, double price)
{
	int lengthOfName = strlen(name);
	this->name = new char[lengthOfName + 1];
	for (int i = 0; i <= lengthOfName; i++)
	{
		this->name[i] = name[i];
	}
	this->price = abs(price);
	this->balanceInStock++;
}
Product::Product(const Product& product)
{
	int lengthOfName = strlen(product.name);
	this->name = new char[lengthOfName + 1];
	for (int i = 0; i <= lengthOfName; i++)
	{
		this->name[i] = product.name[i];
	}
	this->price = abs(product.price);
	this->balanceInStock++;
}
Product& Product::operator = (const Product& product)
{
	int lengthOfName = strlen(product.name);
	this->name = new char[lengthOfName + 1];
	for (int i = 0; i <= lengthOfName; i++)
	{
		this->name[i] = product.name[i];
	}
	this->price = abs(product.price);
	this->balanceInStock++;
	return *this;
}
Product::Product(Product&& product)
{
	int lengthOfName = strlen(product.name);
	this->name = new char[lengthOfName + 1];
	for (int i = 0; i <= lengthOfName; i++)
	{
		this->name[i] = product.name[i];
	}
	this->price = abs(product.price);
	delete[] product.name;
	product.name = nullptr;
	product.price = 0;
}
Product& Product::operator = (Product&& product)
{
	int lengthOfName = strlen(product.name);
	this->name = new char[lengthOfName + 1];
	for (int i = 0; i <= lengthOfName; i++)
	{
		this->name[i] = product.name[i];
	}
	this->price = abs(product.price);
	delete[] product.name;
	product.name = nullptr;
	product.price = 0;
	return *this;
}
Product::~Product()
{
	delete[] this->name;
	this->balanceInStock--;
}
void Product::SetName(const char* name)
{
	int lengthOfName = strlen(name);
	delete[] this->name;
	this->name = new char[lengthOfName + 1];
	for (int i = 0; i <= lengthOfName; i++)
	{
		this->name[i] = name[i];
	}
}
void Product::SetPrice(double price)
{
	if (price > 0)
	{
		this->price = price;
	}
}
const char* Product::GetName()
{
	return this->name;
}
const double Product::GetPrice()
{
	return this->price;
}
const unsigned int Product::GetBalanceInStock()
{
	return this->balanceInStock;
}
void Product::Print(ostream& out)
{
	out << "Product\n" << "Name: " << GetName() << "\nPrice: " << GetPrice() << "\n";
}
ostream& operator << (ostream& out, Product& product)
{
	product.Print(out);
	return out;
}