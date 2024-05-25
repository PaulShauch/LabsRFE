//¬ариант 8
// омпани€, имеюща€ большой товарный оборот на собственных складских площад€х, и,
//ведуща€ вручную весь учЄт, озабочена автоматизацией процесса движени€ товара на складах.
//¬ам необходимо разработать иерархию наследовани€ классов, объедин€ющую все товары, хранимые на складе.
//Ёти классы будут использованы дл€ реализации функции складского учЄта(постановка на учЄт прибывающих
//товаров и сн€тие товаров с учЄта при отправке заказов)
//¬иды товара, хран€щиес€ на складе в насто€щий момент, и свойства,
//которые необходимо хранить в системе учЄта :
//1. Ѕытова€ техника
//Х Ќаименование(строка)
//Х производитель(строка)
//Х цена
//Х остаток на складе(штук)
//2. ¬ерхн€€ одежда
//Х наименование(строка)
//Х размер
//Х материал(строка)
//Х сезон(строка)
//Х цена
//Х остаток на складе(штук)
//3. —портивна€ одежда
//Х наименование(строка)
//Х размер
//Х материал(строка)
//Х цена
//Х остаток на складе(штук)
//4. Ќижнее бельЄ
//Х наименование(строка)
//Х размер
//Х материал(строка)
//Х цена
//Х остаток на складе(штук)

#include <iostream>

using namespace std;

class Product
{
private:
	char* name;
	double price;
	static unsigned int balanceInStock;
public:
	Product(const char* name, double price)
	{
		int lengthOfName = strlen(name);
		this->name = new char[lengthOfName + 1];
		for (int i = 0; i <= lengthOfName; i++)
		{
			this->name[i] = name[i];
		}
		this->price = abs(price);
		this->balanceInStock++;
	}
	Product(const Product& product)
	{
		int lengthOfName = strlen(product.name);
		this->name = new char[lengthOfName + 1];
		for (int i = 0; i <= lengthOfName; i++)
		{
			this->name[i] = product.name[i];
		}
		this->price = abs(product.price);
		this->balanceInStock++;
	}
	Product& operator = (const Product& product)
	{
		int lengthOfName = strlen(product.name);
		this->name = new char[lengthOfName + 1];
		for (int i = 0; i <= lengthOfName; i++)
		{
			this->name[i] = product.name[i];
		}
		this->price = abs(product.price);
		this->balanceInStock++;
		return *this;
	}
	Product(Product&& product)
	{
		int lengthOfName = strlen(product.name);
		this->name = new char[lengthOfName + 1];
		for (int i = 0; i <= lengthOfName; i++)
		{
			this->name[i] = product.name[i];
		}
		this->price = abs(product.price);
		delete[] product.name;
		product.name = nullptr;
		product.price = 0;
	}
	Product& operator = (Product&& product)
	{
		int lengthOfName = strlen(product.name);
		this->name = new char[lengthOfName + 1];
		for (int i = 0; i <= lengthOfName; i++)
		{
			this->name[i] = product.name[i];
		}
		this->price = abs(product.price);
		delete[] product.name;
		product.name = nullptr;
		product.price = 0;
		return *this;
	}
	virtual ~Product()
	{
		delete[] this->name;
		this->balanceInStock--;
	}
	void SetName(const char* name)
	{
		int lengthOfName = strlen(name);
		delete[] this->name;
		this->name = new char[lengthOfName + 1];
		for (int i = 0; i <= lengthOfName; i++)
		{
			this->name[i] = name[i];
		}
	}
	void SetPrice(double price)
	{
		if (price > 0)
		{
			this->price = price;
		}
	}
	const char* GetName()
	{
		return this->name;
	}
	const double GetPrice()
	{
		return this->price;
	}
	virtual const unsigned int GetBalanceInStock()
	{
		return this->balanceInStock;
	}
	virtual void Print(ostream& out)
	{
		out << "Product\n" << "Name: " << GetName() << "\nPrice: " << GetPrice() << "\n";
	}
	friend ostream& operator << (ostream& out, Product& product)
	{
		product.Print(out);
		return out;
	}
};

class Appliances : public Product
{
private:
	char* manufacturer;
	static unsigned int balanceInStockOfAppliances;
public:
	Appliances(const char* name, double price, const char* manufacturer) : Product(name, price)
	{
		int lengthOfManufacturer = strlen(manufacturer);
		this->manufacturer = new char[lengthOfManufacturer + 1];
		for (int i = 0; i <= lengthOfManufacturer; i++)
		{
			this->manufacturer[i] = manufacturer[i];
		}
		this->balanceInStockOfAppliances++;
	}
	Appliances(const Appliances& appliances) : Product(appliances)
	{
		int lengthOfManufacturer = strlen(appliances.manufacturer);
		this->manufacturer = new char[lengthOfManufacturer + 1];
		for (int i = 0; i <= lengthOfManufacturer; i++)
		{
			this->manufacturer[i] = appliances.manufacturer[i];
		}
		this->balanceInStockOfAppliances++;
	}
	Appliances& operator = (const Appliances& appliances)
	{
		Product::operator = (appliances);
		int lengthOfManufacturer = strlen(appliances.manufacturer);
		this->manufacturer = new char[lengthOfManufacturer + 1];
		for (int i = 0; i <= lengthOfManufacturer; i++)
		{
			this->manufacturer[i] = appliances.manufacturer[i];
		}
		this->balanceInStockOfAppliances++;
		return *this;
	}
	Appliances(Appliances&& appliances) : Product(appliances)
	{
		int lengthOfManufacturer = strlen(appliances.manufacturer);
		this->manufacturer = new char[lengthOfManufacturer + 1];
		for (int i = 0; i <= lengthOfManufacturer; i++)
		{
			this->manufacturer[i] = appliances.manufacturer[i];
		}
		delete[] appliances.manufacturer;
		appliances.manufacturer = nullptr;
	}
	Appliances& operator = (Appliances&& appliances)
	{
		Product:: operator =(appliances);
		int lengthOfManufacturer = strlen(appliances.manufacturer);
		this->manufacturer = new char[lengthOfManufacturer + 1];
		for (int i = 0; i <= lengthOfManufacturer; i++)
		{
			this->manufacturer[i] = appliances.manufacturer[i];
		}
		delete[] appliances.manufacturer;
		appliances.manufacturer = nullptr;
		return *this;
	}
	virtual ~Appliances() final 
	{
		delete[] this->manufacturer;
		this->balanceInStockOfAppliances--;
	}
	void SetManufacturer(const char* manufacturer)
	{
		int lengthOfName = strlen(manufacturer);
		delete[] this->manufacturer;
		this->manufacturer = new char[lengthOfName + 1];
		for (int i = 0; i <= lengthOfName; i++)
		{
			this->manufacturer[i] = manufacturer[i];
		}
	}
	const char* GetManufacturer()
	{
		return this->manufacturer;
	}
	virtual const unsigned int GetBalanceInStock() final
	{
		return this->balanceInStockOfAppliances;
	}
	virtual void Print(ostream& out) final
	{
		Product::Print(out);
		out << "Appliences\n" << "Manufacturer: " << GetManufacturer() << "\n";
	}
};

class Wear : public Product
{
private:
	unsigned int size;
	char* material;
	static unsigned int balanceInStockOfWear;
public:
	Wear(const char* name, double price, unsigned int size, const char* material) : Product(name, price)
	{
		this->size = size;
		int lengthOfMaterial = strlen(material);
		this->material = new char[lengthOfMaterial + 1];
		for (int i = 0; i <= lengthOfMaterial; i++)
		{
			this->material[i] = material[i];
		}
		this->balanceInStockOfWear++;
	}
	Wear(const Wear& wear) : Product(wear)
	{
		this->size = wear.size;
		int lengthOfMaterial = strlen(wear.material);
		this->material = new char[lengthOfMaterial + 1];
		for (int i = 0; i <= lengthOfMaterial; i++)
		{
			this->material[i] = wear.material[i];
		}
		this->balanceInStockOfWear++;
	}
	Wear& operator = (const Wear& wear)
	{
		Product::operator=(wear);
		this->size = wear.size;
		int lengthOfMaterial = strlen(wear.material);
		this->material = new char[lengthOfMaterial + 1];
		for (int i = 0; i <= lengthOfMaterial; i++)
		{
			this->material[i] = wear.material[i];
		}
		this->balanceInStockOfWear++;
		return *this;
	}
	Wear(Wear&& wear) : Product(wear)
	{
		this->size = wear.size;
		int lengthOfMaterial = strlen(wear.material);
		this->material = new char[lengthOfMaterial + 1];
		for (int i = 0; i <= lengthOfMaterial; i++)
		{
			this->material[i] = wear.material[i];
		}
		delete wear.material;
		wear.material = nullptr;
		wear.size = 0;
	}
	Wear& operator = (Wear&& wear)
	{
		Product::operator =(wear);
		this->size = wear.size;
		int lengthOfMaterial = strlen(wear.material);
		this->material = new char[lengthOfMaterial + 1];
		for (int i = 0; i <= lengthOfMaterial; i++)
		{
			this->material[i] = wear.material[i];
		}
		delete wear.material;
		wear.material = nullptr;
		wear.size = 0;
		return *this;
	}
	virtual ~Wear() override 
	{
		delete[] this->material;
		this->balanceInStockOfWear--;
	}
	void SetSize(unsigned int size)
	{
		this->size = size;
	}
	void SetMaterial(const char* material)
	{
		int lengthOfName = strlen(material);
		delete[] this->material;
		this->material = new char[lengthOfName + 1];
		for (int i = 0; i <= lengthOfName; i++)
		{
			this->material[i] = material[i];
		}
	}
	int GetSize()
	{
		return this->size;
	}
	const char* GetMaterial()
	{
		return this->material;
	}
	virtual const unsigned int GetBalanceInStock() override
	{
		return this->balanceInStockOfWear;
	}
	virtual void Print(ostream& out) override
	{
		Product::Print(out);
		out << "Wear\n" << "Size: " << GetSize() << "\nMaterial: " << GetMaterial() << "\n";
	}
};

class Outerwear : public Wear
{
private:
	char* season;
	static unsigned int balanceInStockOfOuterwear;
public:
	Outerwear(const char* name, double price, int size, const char* material, const char* season) : Wear(name, price, size, material)
	{
		int lengthOfSeason = strlen(season);
		this->season = new char[lengthOfSeason + 1];
		for (int i = 0; i <= lengthOfSeason; i++)
		{
			this->season[i] = season[i];
		}
		this->balanceInStockOfOuterwear++;
	}
	Outerwear(const Outerwear& outerwear) : Wear(outerwear)
	{
		int lengthOfSeason = strlen(outerwear.season);
		this->season = new char[lengthOfSeason + 1];
		for (int i = 0; i <= lengthOfSeason; i++)
		{
			this->season[i] = outerwear.season[i];
		}
		this->balanceInStockOfOuterwear++;
	}
	Outerwear& operator = (const Outerwear& outerwear)
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
	virtual ~Outerwear() final
	{
		delete[] this->season;
		this->balanceInStockOfOuterwear--;
	}
	Outerwear(Outerwear&& outerwear) : Wear(outerwear)
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
	Outerwear& operator =(Outerwear&& outerwear)
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
	void SetSeason(const char* season)
	{
		int lengthOfName = strlen(season);
		delete[] this->season;
		this->season = new char[lengthOfName + 1];
		for (int i = 0; i <= lengthOfName; i++)
		{
			this->season[i] = season[i];
		}
	}
	const char* GetSeason()
	{
		return this->season;
	}
	virtual const unsigned int GetBalanceInStock() final 
	{
		return this->balanceInStockOfOuterwear;
	}
	virtual void Print(ostream& out) final
	{
		Wear::Print(out);
		out << "Outerwear\n" << "Season: " << GetSeason() << "\n";
	}
};

class Sportswear : public Wear
{
private:
	static unsigned int balanceInStockOfSportswear;
public:
	Sportswear(const char* name, double price,int size, const char* material) : Wear(name, price, size, material)
	{
		this->balanceInStockOfSportswear++;
	}
	Sportswear(const Sportswear& sportswear) : Wear(sportswear)
	{
		this->balanceInStockOfSportswear++;
	}
	Sportswear& operator = (const Sportswear& sportswear)
	{
		Wear::operator=(sportswear);
		this->balanceInStockOfSportswear++;
	}
	Sportswear(Sportswear&& sportswear) : Wear(sportswear) {}
	Sportswear& operator = (Sportswear&& sportswear)
	{
		Wear::operator=(sportswear);
	}
	virtual ~Sportswear() final
	{
		this->balanceInStockOfSportswear--;
	}
	virtual const unsigned int GetBalanceInStock() final 
	{
		return this->balanceInStockOfSportswear;
	}
	virtual void Print(ostream& out) final
	{
		Wear::Print(out);
		out << "Sportswear\n";
	}
};

class Underwear : public Wear
{
private:
	static unsigned int balanceInStockOfUnderwear;
public:
	Underwear(const char* name, double price, int size, const char* material) : Wear(name, price, size, material) 
	{
		this->balanceInStockOfUnderwear++;
	}
	Underwear(const Sportswear& underwear) : Wear(underwear) 
	{
		this->balanceInStockOfUnderwear++;
	}
	Underwear& operator = (const Underwear& underwear)
	{
		Wear::operator=(underwear);
		this->balanceInStockOfUnderwear++;
	}
	Underwear(Underwear&& underwear) : Wear(underwear) {}
	Underwear& operator =(Underwear&& underwear)
	{
		Wear::operator =(underwear);
	}
	virtual ~Underwear() final
	{
		this->balanceInStockOfUnderwear--;
	}
	virtual const unsigned int GetBalanceInStock() final 
	{
		return this->balanceInStockOfUnderwear;
	}
	virtual void Print(ostream& out) final
	{
		Wear::Print(out);
		out << "Underwear\n";
	}
};

unsigned int Product::balanceInStock = 0;
unsigned int Appliances::balanceInStockOfAppliances = 0;
unsigned int Wear::balanceInStockOfWear = 0;
unsigned int Outerwear::balanceInStockOfOuterwear = 0;
unsigned int Sportswear::balanceInStockOfSportswear = 0;
unsigned int Underwear::balanceInStockOfUnderwear = 0;

int main()
{
	
	Appliances* Holodos = new Appliances("Holodos", 300, "Atlant");
	Outerwear* Kurtka = new Outerwear("Kurtka", 30, 89, "sintetic", "autumn");
	Sportswear* Triko = new Sportswear("Triko", 5, 45, "hlopok");
	Underwear* Trusi = new Underwear("Trusi", 1, 47, "lion");
	Trusi->SetName("Semeiniki");
	cout << *Holodos;
	cout << "\n";
	cout << *Kurtka;
	cout << "\n";
	cout << *Triko;
	cout << "\n";
	cout << *Trusi;
	cout << "\n";
	cout << "Get balance in stock of underwear: " << Trusi->GetBalanceInStock() << "\n";
	cout << "Get balance in stock of wear: " << Trusi->Wear::GetBalanceInStock() << "\n";
	delete Triko;
	cout << "Get balance in stock of wear: " << Trusi->Wear::GetBalanceInStock() << "\n";
	cout << "Get balance in stock of product: " << Trusi->Product::GetBalanceInStock() << "\n";
	return 0;
}