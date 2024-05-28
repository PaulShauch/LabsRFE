//–еализовать класс Ђодномерный динамический массив из потомков - объектов,
//описанных в 6.1ї.
//–еализовать следующие методы :
//Х создание массива;
//Х занесение объекта в массив;
//Х удаление объекта из массива;
//Х вывод на экран элементов массива с соответствующими пол€ми дл€ каждого
//объекта;
//Х удаление массива.
//ќпределить: конструктор без параметров, виртуальные методы.”честь
//требовани€ Ђправила п€тиї(конструктор копировани€, оператор копировани€,
//конструктор перемещени€, оператор перемещени€, деструктор).
//¬ыполнить тестирование написанных методов(методы шаблоны, которые нигде не вызываютс€,
//никогда не компилируютс€).

#include <iostream>
#include "Product.h"
#include "Appliances.h"
#include "Wear.h"
#include "Outerwear.h"
#include "Sportswear.h"
#include "Underwear.h"
#include "Stock.h"

using namespace std;

unsigned int Product::balanceInStock = 0;
unsigned int Appliances::balanceInStockOfAppliances = 0;
unsigned int Wear::balanceInStockOfWear = 0;
unsigned int Outerwear::balanceInStockOfOuterwear = 0;
unsigned int Sportswear::balanceInStockOfSportswear = 0;
unsigned int Underwear::balanceInStockOfUnderwear = 0;

int main()
{
	Stock stock;
	stock.Create();
	Appliances* Holodos = new Appliances("Holodos", 300, "Atlant");
	Outerwear* Kurtka = new Outerwear("Kurtka", 30, 89, "sintetic", "autumn");
	Sportswear* Triko = new Sportswear("Triko", 5, 45, "hlopok");
	Underwear* Trusi = new Underwear("Trusi", 1, 47, "lion");
	stock.AddProduct(Holodos);
	stock.AddProduct(Kurtka);
	stock.AddProduct(Triko);
	stock.AddProduct(Trusi);
	stock.Print();
	stock.DeleteProduct(2);
	stock.Print();
	stock.DeleteStock();
	return 0;
}