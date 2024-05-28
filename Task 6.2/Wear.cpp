#include <iostream>
#include "Wear.h"

using namespace std;

Wear::Wear(const char* name, double price, unsigned int size, const char* material) : Product(name, price)
{
	this->size = size;
	int lengthOfMaterial = strlen(material);
	this->material = new char[lengthOfMaterial + 1];
	for (int i = 0; i <= lengthOfMaterial; i++)
	{
		this->material[i] = material[i];
	}
	this->balanceInStockOfWear++;
}
Wear::Wear(const Wear& wear) : Product(wear)
{
	this->size = wear.size;
	int lengthOfMaterial = strlen(wear.material);
	this->material = new char[lengthOfMaterial + 1];
	for (int i = 0; i <= lengthOfMaterial; i++)
	{
		this->material[i] = wear.material[i];
	}
	this->balanceInStockOfWear++;
}
Wear& Wear::operator = (const Wear& wear)
{
	Product::operator=(wear);
	this->size = wear.size;
	int lengthOfMaterial = strlen(wear.material);
	this->material = new char[lengthOfMaterial + 1];
	for (int i = 0; i <= lengthOfMaterial; i++)
	{
		this->material[i] = wear.material[i];
	}
	this->balanceInStockOfWear++;
	return *this;
}
Wear::Wear(Wear&& wear) : Product(wear)
{
	this->size = wear.size;
	int lengthOfMaterial = strlen(wear.material);
	this->material = new char[lengthOfMaterial + 1];
	for (int i = 0; i <= lengthOfMaterial; i++)
	{
		this->material[i] = wear.material[i];
	}
	delete wear.material;
	wear.material = nullptr;
	wear.size = 0;
}
Wear& Wear::operator = (Wear&& wear)
{
	Product::operator =(wear);
	this->size = wear.size;
	int lengthOfMaterial = strlen(wear.material);
	this->material = new char[lengthOfMaterial + 1];
	for (int i = 0; i <= lengthOfMaterial; i++)
	{
		this->material[i] = wear.material[i];
	}
	delete wear.material;
	wear.material = nullptr;
	wear.size = 0;
	return *this;
}
Wear::~Wear()
{
	delete[] this->material;
	this->balanceInStockOfWear--;
}
void Wear::SetSize(unsigned int size)
{
	this->size = size;
}
void Wear::SetMaterial(const char* material)
{
	int lengthOfName = strlen(material);
	delete[] this->material;
	this->material = new char[lengthOfName + 1];
	for (int i = 0; i <= lengthOfName; i++)
	{
		this->material[i] = material[i];
	}
}
int Wear::GetSize()
{
	return this->size;
}
const char* Wear::GetMaterial()
{
	return this->material;
}
const unsigned int Wear::GetBalanceInStock()
{
	return this->balanceInStockOfWear;
}
void Wear::Print(ostream& out)
{
	Product::Print(out);
	out << "Wear\n" << "Size: " << GetSize() << "\nMaterial: " << GetMaterial() << "\n";
}