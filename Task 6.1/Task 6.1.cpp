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
#include "Product.h"
#include "Appliances.h"
#include "Wear.h"
#include "Outerwear.h"
#include "Sportswear.h"
#include "Underwear.h"

using namespace std;

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
	delete Holodos;
	delete Kurtka;
	delete Trusi;
	return 0;
}