//Дана последовательность натуральных чисел, в которой каждое число <=104.
//Последовательность генерируется случайным образом или вводится с
//клавиатуры.Длина последовательности n  109
//8.Получить итоговый массив за
//один просмотр элементов(не храня в памяти всю последовательность) :
//образованный из чисел, встречающихся в исходной последовательности ровно
//два раза, по возрастанию(без повторений);

#include <iostream>
#include "Vector.h"

using namespace std;

int main()
{
	int N = 10000;
	cout << "Enter number of elements:\n";
	int n; cin >> n;
	Vector<int> numbers(N);
	/*Vector<int> array(numbers);
	Vector<int> arr(N);
	arr = array;
	Vector<int> massiv = move(arr);
	Vector<int> mass(N);
	mass = move(massiv);*/
	cout << "0 - Keyboard:\n" << "Other numbers - random:\n";
	bool b; cin >> b;
	switch (b)
	{
	case 0:
		for (int i = 0; i < n; i++)
		{
			int a; cin >> a;
			if (a > 0 && a <= N)
			{
				numbers[a]++;
			}
		}
		break;
	default:
		for (int i = 0; i < n; i++)
		{
			int a = rand() % n + 1;
			cout << a << " ";
			numbers[a]++;
		}
	}
	cout << endl;
	for (int i = 0; i < numbers.amountOfNumbers(); i++)
	{
		if (numbers[i] == 2)
		{
			std::cout << i << " ";
		}
	}
	cout << "\n";
	return 0;
}