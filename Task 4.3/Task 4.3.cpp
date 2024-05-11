//8. Даны натуральное число n, действительные числа a1, a2, ..., a2n.Получить
//anan 1 an 1an 2 a1a2n + +− + +... + .

#include <iostream>
#include "List.h"

using namespace std;

int main()
{
	int n;
	cin >> n;
	List<double> numbers(rand() % 2 * n + (double)rand() / rand());
	for (int i = 1; i < 2 * n; i++)
	{
		numbers.push(i, rand() % 2 * n + (double)rand() / rand());
	}
	numbers.print();
	double sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += numbers.get(i - 1) * numbers.get(2 * n - i);
	}
	cout << sum;
	return 0;
}