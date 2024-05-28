#pragma once
#include <iostream>
#include "Product.h"
#include "Appliances.h"
#include "Wear.h"
#include "Outerwear.h"
#include "Sportswear.h"
#include "Underwear.h"

using namespace std;

class Appliances : public Product
{
private:
	char* manufacturer;
	static unsigned int balanceInStockOfAppliances;
public:
	Appliances(const char* name, double price, const char* manufacturer);
	Appliances(const Appliances& appliances);
	Appliances& operator = (const Appliances& appliances);
	Appliances(Appliances&& appliances);
	Appliances& operator = (Appliances&& appliances);
	~Appliances() final;
	void SetManufacturer(const char* manufacturer);
	const char* GetManufacturer();
	const unsigned int GetBalanceInStock() final;
	void Print(ostream& out) final;
};