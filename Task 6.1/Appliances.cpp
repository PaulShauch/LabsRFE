#include<iostream>
#include "Appliances.h"

using namespace std;

Appliances::Appliances(const char* name, double price, const char* manufacturer) : Product(name, price)
{
	int lengthOfManufacturer = strlen(manufacturer);
	this->manufacturer = new char[lengthOfManufacturer + 1];
	for (int i = 0; i <= lengthOfManufacturer; i++)
	{
		this->manufacturer[i] = manufacturer[i];
	}
	this->balanceInStockOfAppliances++;
}
Appliances::Appliances(const Appliances& appliances) : Product(appliances)
{
	int lengthOfManufacturer = strlen(appliances.manufacturer);
	this->manufacturer = new char[lengthOfManufacturer + 1];
	for (int i = 0; i <= lengthOfManufacturer; i++)
	{
		this->manufacturer[i] = appliances.manufacturer[i];
	}
	this->balanceInStockOfAppliances++;
}
Appliances& Appliances::operator = (const Appliances& appliances)
{
	Product::operator = (appliances);
	int lengthOfManufacturer = strlen(appliances.manufacturer);
	this->manufacturer = new char[lengthOfManufacturer + 1];
	for (int i = 0; i <= lengthOfManufacturer; i++)
	{
		this->manufacturer[i] = appliances.manufacturer[i];
	}
	this->balanceInStockOfAppliances++;
	return *this;
}
Appliances::Appliances(Appliances&& appliances) : Product(appliances)
{
	int lengthOfManufacturer = strlen(appliances.manufacturer);
	this->manufacturer = new char[lengthOfManufacturer + 1];
	for (int i = 0; i <= lengthOfManufacturer; i++)
	{
		this->manufacturer[i] = appliances.manufacturer[i];
	}
	delete[] appliances.manufacturer;
	appliances.manufacturer = nullptr;
}
Appliances& Appliances::operator = (Appliances&& appliances)
{
	Product:: operator =(appliances);
	int lengthOfManufacturer = strlen(appliances.manufacturer);
	this->manufacturer = new char[lengthOfManufacturer + 1];
	for (int i = 0; i <= lengthOfManufacturer; i++)
	{
		this->manufacturer[i] = appliances.manufacturer[i];
	}
	delete[] appliances.manufacturer;
	appliances.manufacturer = nullptr;
	return *this;
}
Appliances::~Appliances()
{
	delete[] this->manufacturer;
	this->balanceInStockOfAppliances--;
}
void Appliances::SetManufacturer(const char* manufacturer)
{
	int lengthOfName = strlen(manufacturer);
	delete[] this->manufacturer;
	this->manufacturer = new char[lengthOfName + 1];
	for (int i = 0; i <= lengthOfName; i++)
	{
		this->manufacturer[i] = manufacturer[i];
	}
}
const char* Appliances::GetManufacturer()
{
	return this->manufacturer;
}
const unsigned int Appliances::GetBalanceInStock()
{
	return this->balanceInStockOfAppliances;
}
void Appliances::Print(ostream& out)
{
	Product::Print(out);
	out << "Appliences\n" << "Manufacturer: " << GetManufacturer() << "\n";
}