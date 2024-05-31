#pragma once
#include <iostream>
#include "Product.h"

using namespace std;

class Wear : public Product
{
protected:
	unsigned int size;
	char* material;
	static unsigned int balanceInStockOfWear;
public:
	Wear(const char* name, double price, unsigned int size, const char* material);
	Wear(const Wear& wear);
	Wear& operator = (const Wear& wear);
	Wear(Wear&& wear);
	Wear& operator = (Wear&& wear);
	virtual ~Wear() override;
	void SetSize(unsigned int size);
	void SetMaterial(const char* material);
	int GetSize();
	const char* GetMaterial();
	virtual const unsigned int GetBalanceInStock() override;
	virtual void Print(ostream& out) override;
};