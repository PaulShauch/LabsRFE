#pragma once
#include <iostream>
#include "Wear.h"

class Sportswear : public Wear
{
private:
	static unsigned int balanceInStockOfSportswear;
public:
	Sportswear(const char* name, double price, int size, const char* material);
	Sportswear(const Sportswear& sportswear);
	Sportswear& operator = (const Sportswear& sportswear);
	Sportswear(Sportswear&& sportswear);
	Sportswear& operator = (Sportswear&& sportswear);
	~Sportswear() final;
	const unsigned int GetBalanceInStock() final;
	void Print(ostream& out) final;
};