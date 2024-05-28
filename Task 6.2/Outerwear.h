#pragma once
#include <iostream>
#include "Wear.h"

class Outerwear : public Wear
{
private:
	char* season;
	static unsigned int balanceInStockOfOuterwear;
public:
	Outerwear(const char* name, double price, int size, const char* material, const char* season);
	Outerwear(const Outerwear& outerwear);
	Outerwear& operator = (const Outerwear& outerwear);
	~Outerwear() final;
	Outerwear(Outerwear&& outerwear);
	Outerwear& operator =(Outerwear&& outerwear);
	void SetSeason(const char* season);
	const char* GetSeason();
	const unsigned int GetBalanceInStock() final;
	void Print(ostream& out) final;
};