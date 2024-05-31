#include <iostream>
#include "Sportswear.h"

using namespace std;

Sportswear::Sportswear(const char* name, double price, int size, const char* material) : Wear(name, price, size, material)
{
	this->balanceInStockOfSportswear++;
}
Sportswear::Sportswear(const Sportswear& sportswear) : Wear(sportswear)
{
	this->balanceInStockOfSportswear++;
}
Sportswear& Sportswear::operator = (const Sportswear& sportswear)
{
	Wear::operator=(sportswear);
	this->balanceInStockOfSportswear++;
	return *this;
}
Sportswear::Sportswear(Sportswear && sportswear) : Wear(sportswear) {}
Sportswear& Sportswear::operator = (Sportswear && sportswear)
{
	Wear::operator=(sportswear);
	return *this;
}
Sportswear::~Sportswear()
{
	this->balanceInStockOfSportswear--;
}
const unsigned int Sportswear::GetBalanceInStock()
{
	return this->balanceInStockOfSportswear;
}
void Sportswear::Print(ostream& out)
{
	Wear::Print(out);
	out << "Sportswear\n";
}