//Получить квадратную матрицу B порядка n, каждый элемент bij которой равен максимуму из элементов исходной квадратной матрицы А порядка n,
//расположенных в закрашенной области(включая границы), определяемой соответствующими индексами i, j по рисунку.Матрицу A сгенерировать случайно.
//Корректность работы алгоритма продемонстировать на матрице 6х6.
//Быстродействие продемонстрировать на матрице 10000х10000 без вывода матрицы на экран
//(такой большой массив рекомендуется объявить в глобальной области видимости)
//4 Вариант

#include <iostream>
#include <iomanip>

const int n = 10000;
int A[n][n] = { 0 };
int C[n][n] = { 0 };

int main()
{
//Матрица 6х6
	/*const int n = 6;
	int A[n][n] = { 0 };*/
//
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			A[i][j] = rand() % 100;
		}
	}
	std::cout << "Success random numbers\n";
//Вывод изначальной матрицы	
	/*for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << std::setw(3) << A[i][j];
		}
		std::cout << std::endl;
	}*/
	//std::cout << std::endl;
// 
//Матрица 6х6
	//int B[n][n] = { 0 };
// 
//Закомментировано решение "в лоб", при матрице 10000*10000 не выполнится за адекватное время
	/*for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int maxElement = -2'147'483'648;
			if (i < n / 2)
			{
				if (j < n / 2)
				{
					for (int k = i; k <= n - i - 1; k++)
					{
						for (int l = j; l <= n - j - 1; l++)
						{
							if (A[k][l] > maxElement)
							{
								maxElement = A[k][l];
							}
						}
					}
				}
				else
				{
					for (int k = i; k <= n - i - 1; k++)
					{
						for (int l = n - j - 1; l <= j; l++)
						{
							if (A[k][l] > maxElement)
							{
								maxElement = A[k][l];
							}
						}
					}
				}
			}
			else
			{
				if (j < n / 2)
				{
					for (int k = n - i - 1; k <= i; k++)
					{
						for (int l = j; l <= n - j - 1; l++)
						{
							if (A[k][l] > maxElement)
							{
								maxElement = A[k][l];
							}
						}
					}
				}
				else
				{
					for (int k = n - i - 1; k <= i; k++)
					{
						for (int l = n - j - 1; l <= j; l++)
						{
							if (A[k][l] > maxElement)
							{
								maxElement = A[k][l];
							}
						}
					}
				}
			}
			B[i][j] = maxElement;
		}
	}*/
	/*for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << std::setw(3) << B[i][j];
		}
		std::cout << std::endl;
	}*/
	//std::cout << std::endl;
//
//Матрица 6х6
	//int C[n][n] = { 0 };
//
	if (n % 2 == 1)
	{
		C[n / 2][n / 2] = A[n / 2][n / 2];
		for (int i = n / 2; i < n - 1; i++)
		{
			int maxElement = C[i][n / 2];
			if (A[i + 1][n / 2] > maxElement) maxElement = A[i + 1][n / 2];
			if (A[n - i - 2][n / 2] > maxElement) maxElement = A[n - i - 2][n / 2];
			C[i + 1][n / 2] = C[n - i - 2][n / 2] = maxElement;
		}
		for (int i = n / 2; i < n - 1; i++)
		{
			int maxElement = C[n / 2][i];
			if (A[n / 2][i + 1] > maxElement) maxElement = A[n / 2][i + 1];
			if (A[n / 2][n - i - 2] > maxElement) maxElement = A[n / 2][n - i - 2];
			C[n / 2][i + 1] = C[n / 2][n - i - 2] = maxElement;
		}
	}
	else
	{
		{
			int maxElement = A[n / 2][n / 2];
			if (A[n / 2 - 1][n / 2] > maxElement) maxElement = A[n / 2 - 1][n / 2];
			if (A[n / 2 - 1][n / 2 - 1] > maxElement) maxElement = A[n / 2 - 1][n / 2 - 1];
			if (A[n / 2][n / 2 - 1] > maxElement) maxElement = A[n / 2][n / 2 - 1];
			C[n / 2][n / 2] = C[n / 2 - 1][n / 2] = C[n / 2 - 1][n / 2 - 1] = C[n / 2][n / 2 - 1] = maxElement;
		}
		for (int i = n / 2; i < n - 1; i++)
		{
			int maxElement = C[i][n / 2];
			if (A[i + 1][n / 2] > maxElement) maxElement = A[i + 1][n / 2];
			if (A[n - i - 2][n / 2] > maxElement) maxElement = A[n - i - 2][n / 2];
			if (A[i + 1][n / 2 - 1] > maxElement) maxElement = A[i + 1][n / 2 - 1];
			if (A[n - i - 2][n / 2 - 1] > maxElement) maxElement = A[n - i - 2][n / 2 - 1];
			C[i + 1][n / 2] = C[n - i - 2][n / 2] = C[i + 1][n / 2 - 1] = C[n - i - 2][n / 2 - 1] = maxElement;
		}
		for (int i = n / 2; i < n - 1; i++)
		{
			int maxElement = C[n / 2][i];
			if (A[n / 2][i + 1] > maxElement) maxElement = A[n / 2][i + 1];
			if (A[n / 2][n - i - 2] > maxElement) maxElement = A[n / 2][n - i - 2];
			if (A[n / 2 - 1][i + 1] > maxElement) maxElement = A[n / 2 - 1][i + 1];
			if (A[n / 2 - 1][n - i - 2] > maxElement) maxElement = A[n / 2 - 1][n - i - 2];
			C[n / 2][i + 1] = C[n / 2][n - i - 2] = C[n / 2 - 1][i + 1] = C[n / 2 - 1][n - i - 2] = maxElement;
		}
	}
	std::cout << "Success rows and columns\n";
	for (int i = n / 2; i < n - 1; i++)
	{
		for (int j = n / 2; j < n - 1; j++)
		{
			int maxElement = C[i + 1][j];
			if (C[i][j + 1] > maxElement) maxElement = C[i][j + 1];
			if (A[i + 1][j + 1] > maxElement) maxElement = A[i + 1][j + 1];
			if (A[i + 1][n - j - 2] > maxElement) maxElement = A[i + 1][n - j - 2];
			if (A[n - i - 2][n - j - 2] > maxElement) maxElement = A[n - i - 2][n - j - 2];
			if (A[n - i - 2][j + 1] > maxElement) maxElement = A[n - i - 2][j + 1];
			C[i + 1][j + 1] = C[i + 1][n - j - 2] = C[n - i - 2][n - j - 2] = C[n - i - 2][j + 1] = maxElement;
		}
	}
	std::cout << "Success all matrix\n";
//Вывод на экран полученной матрицы
	/*for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << std::setw(3) << C[i][j];
		}
		std::cout << std::endl;
	}*/
//
	return 0;
}