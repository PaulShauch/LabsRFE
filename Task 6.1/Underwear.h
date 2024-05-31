#pragma once
#include <iostream>
#include "Wear.h"

using namespace std;

class Underwear : public Wear
{
private:
	static unsigned int balanceInStockOfUnderwear;
public:
	Underwear(const char* name, double price, int size, const char* material);
	Underwear(const Underwear& underwear);
	Underwear& operator = (const Underwear& underwear);
	Underwear(Underwear&& underwear);
	Underwear& operator =(Underwear&& underwear);
	~Underwear() final;
	const unsigned int GetBalanceInStock() final;
	void Print(ostream& out) final;
};