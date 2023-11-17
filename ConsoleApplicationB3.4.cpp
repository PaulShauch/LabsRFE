//4. Получить последовательность dk, dk–1, …, d0 десятичных цифр числа N!(N –
//	натуральное число, N > 100), т.е.такую целочисленную последовательность,
//  в которой каждый член di удовлетворяет условию 0  di  9 и
//	dk  10k + dk–1  10k–1 + … d0 = N!
#include <iostream>

const int n = 10000;
int D[n] = { 0 };

int main()
{
	int N = 1000;
	const int x = 10;
	int E[x] = { 0 };
	D[0] = 1;
	int countOfFactorial = 1;
	for (int i = 2; i <= N; i++)
	{
		int countOfN = 0;
		int y = i;
		for (int j = 0; y > 0; j++)
		{
			E[j] = y % 10;
			y /= 10;
			countOfN++;
		}
		int A[x][n] = { 0 };
		for (int j = 0; j < countOfN; j++)
		{
			int dop = 0;
			for (int k = 0; k < countOfFactorial; k++)
			{
				int mult = D[k] * E[j];
				A[j][k+j] = mult % 10 + dop;
				dop = mult / 10;
			}
			A[j][countOfFactorial+j] = dop;
		}
		if (A[countOfN - 1][countOfFactorial+countOfN-1] != 0)
		{
			countOfFactorial += countOfN;
		}
		else
		{
			countOfFactorial += countOfN - 1;
		}
		int dop = 0;
		for (int k = 0; k < countOfFactorial; k++)
		{
			int sum = 0;
			for (int j = 0; j < countOfN; j++)
			{
				sum += A[j][k];
			}
			sum += dop;
			D[k] = sum % 10;
			dop = sum / 10;
		}
		if (dop != 0)
		{
			D[countOfFactorial] = dop;
			countOfFactorial++;
		}
	}
	for (int i = countOfFactorial - 1; i >= 0; i--)
	{
		std::cout << D[i];
	}
	return 0;
}