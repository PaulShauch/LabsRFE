#pragma once
#include <iostream>
#include "Product.h"
#include "Appliances.h"
#include "Wear.h"
#include "Outerwear.h"
#include "Sportswear.h"
#include "Underwear.h"

using namespace std;

class Stock
{
private:
	Product** array;
	int balance;
	int size;
public:
	Stock();
	Stock(const Stock& stock);
	Stock& operator =(const Stock& stock);
	Stock(Stock&& stock);
	Stock& operator =(Stock&& stock);
	~Stock();
	void Create();
	void AddProduct(Product* product);
	void DeleteProduct(int index);
	void Print();
	void DeleteStock();
};