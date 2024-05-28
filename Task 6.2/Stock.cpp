#include <iostream>
#include "Stock.h"

using namespace std;

Stock::Stock()
{
	this->array = nullptr;
	this->size = 0;
	this->balance = 0;
}
Stock::Stock(const Stock& stock)
{
	this->array = new Product * [stock.balance];
	for (int i = 0; i < stock.balance; i++)
	{
		this->array[i] = stock.array[i];
	}
	this->balance = stock.balance;
	this->size = this->balance;
}
Stock& Stock::operator =(const Stock& stock)
{
	this->array = new Product * [stock.balance];
	for (int i = 0; i < stock.balance; i++)
	{
		this->array[i] = stock.array[i];
	}
	this->balance = stock.balance;
	this->size = this->balance;
	return *this;
}
Stock::Stock(Stock&& stock)
{
	this->array = new Product * [stock.balance];
	for (int i = 0; i < stock.balance; i++)
	{
		this->array[i] = stock.array[i];
	}
	this->balance = stock.balance;
	this->size = this->balance;
	for (int i = 0; i < stock.balance; i++)
	{
		delete stock.array[i];
	}
	delete[] stock.array;
	stock.array = nullptr;
	stock.balance = 0;
	stock.size = 0;
}
Stock& Stock::operator =(Stock&& stock)
{
	this->array = new Product * [stock.balance];
	for (int i = 0; i < stock.balance; i++)
	{
		this->array[i] = stock.array[i];
	}
	this->balance = stock.balance;
	this->size = this->balance;
	for (int i = 0; i < stock.balance; i++)
	{
		delete stock.array[i];
	}
	delete[] stock.array;
	stock.array = nullptr;
	stock.balance = 0;
	stock.size = 0;
	return *this;
}
Stock::~Stock()
{
	DeleteStock();
}
void Stock::AddProduct(Product* product)
{
	if (this->size == 0)
	{
		this->size = 1;
		this->balance = 1;
		this->array = new Product * [1];
		this->array[0] = product;
	}
	else
	{
		if (this->balance >= this->size)
		{
			this->size *= 2;
			Product** arr = new Product * [this->size];
			for (int i = 0; i < this->balance; i++)
			{
				arr[i] = this->array[i];
			}
			arr[this->balance] = product;
			delete[] this->array;
			this->array = arr;
			this->balance++;
		}
		else
		{
			this->array[this->balance] = product;
			this->balance++;
		}
	}
}
void Stock::DeleteProduct(int index)
{
	if (index < 0 && index >= this->balance) return;
	else
	{
		delete this->array[index];
		this->balance--;
		for (int i = index; i < this->balance; i++)
		{
			this->array[i] = this->array[i + 1];
		}
	}
}
void Stock::Print()
{
	for (int i = 0; i < this->balance; i++)
	{
		cout << *this->array[i] << "\n";
	}
}
void Stock::DeleteStock()
{
	for (int i = 0; i < this->balance; i++)
	{
		delete this->array[i];
	}
	delete[] this->array;
	this->array = nullptr;
	this->balance = 0;
	this->size = 0;
}
void Stock::Create()
{
	cout << "Input number of products:\n";
	unsigned int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		unsigned int x;
		cout << "What product you want to create?\n1 - outerwear\n2 - sportswear\n3 - underwear\n4 - appliances\nother number - nothing\n";
		cin >> x;
		if (x == 1)
		{
			char* name = new char[100];
			cout << "Enter name:\n";
			cin.clear();
			cin.ignore(32767, '\n');
			cin.getline(name, 100);
			cout << "Enter price:\n";
			double price; cin >> price;
			cout << "Enter size:\n";
			int size; cin >> size;
			cout << "Enter material:\n";
			char* material = new char[100];
			cin.clear();
			cin.ignore(32767, '\n');
			cin.getline(material, 100);
			cout << "Enter season:\n";
			char* season = new char[100];
			cin.getline(season, 100);
			Outerwear* outerwear = new Outerwear(name, price, size, material, season);
			AddProduct(outerwear);
		}
		else if (x == 2)
		{
			char* name = new char[100];
			cout << "Enter name:\n";
			cin.clear();
			cin.ignore(32767, '\n');
			cin.getline(name, 100);
			cout << "Enter price:\n";
			double price; cin >> price;
			cout << "Enter size:\n";
			int size; cin >> size;
			cout << "Enter material:\n";
			char* material = new char[100];
			cin.clear();
			cin.ignore(32767, '\n');
			cin.getline(material, 100);
			Sportswear* sportswear = new Sportswear(name, price, size, material);
			AddProduct(sportswear);
		}
		else if (x == 3)
		{
			char* name = new char[100];
			cout << "Enter name:\n";
			cin.clear();
			cin.ignore(32767, '\n');
			cin.getline(name, 100);
			cout << "Enter price:\n";
			double price; cin >> price;
			cout << "Enter size:\n";
			int size; cin >> size;
			cout << "Enter material:\n";
			char* material = new char[100];
			cin.clear();
			cin.ignore(32767, '\n');
			cin.getline(material, 100);
			Underwear* underwear = new Underwear(name, price, size, material);
			AddProduct(underwear);
		}
		else if(x== 4)
		{
			char* name = new char[100];
			cout << "Enter name:\n";
			cin.clear();
			cin.ignore(32767, '\n');
			cin.getline(name, 100);
			cout << "Enter price:\n";
			double price; cin >> price;
			cout << "Enter material:\n";
			char* manufacturer = new char[100];
			cin.clear();
			cin.ignore(32767, '\n');
			cin.getline(manufacturer, 100);
			Appliances* appliances = new Appliances(name, price, manufacturer);
			AddProduct(appliances);
		}
	}
}