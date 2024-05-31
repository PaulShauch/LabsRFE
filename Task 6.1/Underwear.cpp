#include <iostream>
#include "Underwear.h"

using namespace std;

Underwear::Underwear(const char* name, double price, int size, const char* material) : Wear(name, price, size, material)
{
	this->balanceInStockOfUnderwear++;
}
Underwear::Underwear(const Underwear& underwear) : Wear(underwear)
{
	this->balanceInStockOfUnderwear++;
}
Underwear& Underwear::operator = (const Underwear& underwear)
{
	Wear::operator=(underwear);
	this->balanceInStockOfUnderwear++;
	return *this;
}
Underwear::Underwear(Underwear&& underwear) : Wear(underwear) {}
Underwear& Underwear::operator =(Underwear&& underwear)
{
	Wear::operator =(underwear);
	return *this;
}
Underwear::~Underwear()
{
	this->balanceInStockOfUnderwear--;
}
const unsigned int Underwear::GetBalanceInStock()
{
	return this->balanceInStockOfUnderwear;
}
void Underwear::Print(ostream& out)
{
	Wear::Print(out);
	out << "Underwear\n";
}