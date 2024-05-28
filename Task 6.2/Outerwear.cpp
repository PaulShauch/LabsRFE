#include <iostream>
#include "Outerwear.h"

using namespace std;

Outerwear::Outerwear(const char* name, double price, int size, const char* material, const char* season) : Wear(name, price, size, material)
{
	int lengthOfSeason = strlen(season);
	this->season = new char[lengthOfSeason + 1];
	for (int i = 0; i <= lengthOfSeason; i++)
	{
		this->season[i] = season[i];
	}
	this->balanceInStockOfOuterwear++;
}
Outerwear::Outerwear(const Outerwear& outerwear) : Wear(outerwear)
{
	int lengthOfSeason = strlen(outerwear.season);
	this->season = new char[lengthOfSeason + 1];
	for (int i = 0; i <= lengthOfSeason; i++)
	{
		this->season[i] = outerwear.season[i];
	}
	this->balanceInStockOfOuterwear++;
}
Outerwear& Outerwear::operator = (const Outerwear& outerwear)
{
	Wear::operator=(outerwear);
	int lengthOfSeason = strlen(outerwear.season);
	this->season = new char[lengthOfSeason + 1];
	for (int i = 0; i <= lengthOfSeason; i++)
	{
		this->season[i] = outerwear.season[i];
	}
	this->balanceInStockOfOuterwear++;
	return *this;
}
Outerwear::~Outerwear()
{
	delete[] this->season;
	this->balanceInStockOfOuterwear--;
}
Outerwear::Outerwear(Outerwear&& outerwear) : Wear(outerwear)
{
	int lengthOfSeason = strlen(outerwear.season);
	this->season = new char[lengthOfSeason + 1];
	for (int i = 0; i <= lengthOfSeason; i++)
	{
		this->season[i] = outerwear.season[i];
	}
	delete[] outerwear.season;
	outerwear.season = nullptr;
}
Outerwear& Outerwear::operator =(Outerwear&& outerwear)
{
	Wear::operator =(outerwear);
	int lengthOfSeason = strlen(outerwear.season);
	this->season = new char[lengthOfSeason + 1];
	for (int i = 0; i <= lengthOfSeason; i++)
	{
		this->season[i] = outerwear.season[i];
	}
	delete[] outerwear.season;
	outerwear.season = nullptr;
	return *this;
}
void Outerwear::SetSeason(const char* season)
{
	int lengthOfName = strlen(season);
	delete[] this->season;
	this->season = new char[lengthOfName + 1];
	for (int i = 0; i <= lengthOfName; i++)
	{
		this->season[i] = season[i];
	}
}
const char* Outerwear::GetSeason()
{
	return this->season;
}
const unsigned int Outerwear::GetBalanceInStock()
{
	return this->balanceInStockOfOuterwear;
}
void Outerwear::Print(ostream& out)
{
	Wear::Print(out);
	out << "Outerwear\n" << "Season: " << GetSeason() << "\n";
}