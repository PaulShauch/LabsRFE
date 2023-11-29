#pragma once

void FillAscending(char array[], const int N);

void FillAscending(int array[], const int N);

void FillAscending(float array[], const int N);

void FillAscending(double array[], const int N);

void FillDescending(char array[], const int N);

void FillDescending(int array[], const int N);

void FillDescending(float array[], const int N);

void FillDescending(double array[], const int N);

void FillRandom(char array[], const int N);

void FillRandom(int array[], const int N);

void FillRandom(float array[], const int N);

void FillRandom(double array[], const int N);

template<class T>
void SortInsertionSimple(T array[], const int N)
{
	double averageCompares = (N * N + N - 2) / 4;
	double averageMoves = (N * N + 9 * N - 10) / 4;
	int countCompare = 0;
	int countMove = 0;
	for (int i = 1; i < N; i++)
	{
		T x = array[i];
		countMove++;
		int j = i - 1;
		while (x < array[j])
		{
			countCompare++;
			array[j + 1] = array[j];
			countMove++;
			j--;
			if (j < 0)
			{
				break;
			}
		}
		array[j + 1] = x;
		countMove++;
	}
	std::cout << "SortInsertionSimple:\nCompares - " << countCompare;
	if (countCompare < averageCompares) std::cout << " < ";
	else if (countCompare > averageCompares) std::cout << " > ";
	else std::cout << " = ";
	std::cout << averageCompares << " (theoretical average count of compares)\n";
	std::cout << "Moves - " << countMove;
	if (countMove < averageMoves) std::cout << " < ";
	else if (countMove > averageMoves) std::cout << " > ";
	else std::cout << " = ";
	std::cout << averageMoves << " (theoretical average count of moves)\n";
}

template<class T>
void SortInsertionBinary(T array[], const int N)
{
	double c = 1.44269;
	double AverageCompares = (log2(N) - c) * N + c;
	double AverageMoves = (N * N + 9 * N - 10) / 4;
	int countCompare = 0;
	int countMove = 0;
	for (int i = 1; i < N; i++)
	{
		T x = array[i];
		countMove++;
		int bottom = 0;
		int top = i - 1;
		while (bottom <= top)
		{
			int mid = (bottom + top) / 2;
			if (x < array[mid])
			{
				top = mid - 1;
			}
			else
			{
				bottom = mid + 1;
			}
			countCompare++;
		}
		for (int j = i - 1; j >= bottom; j--)
		{
			array[j + 1] = array[j];
			countMove++;
		}
		array[bottom] = x;
		countMove++;
	}
	std::cout << "SortInsertionBinary:\nCompares - " << countCompare;
	if (countCompare < AverageCompares) std::cout << " < ";
	else if (countCompare > AverageCompares) std::cout << " > ";
	else std::cout << " = ";
	std::cout << AverageCompares << " (theoretical average count of compares)\n";
	std::cout << "Moves - " << countMove;
	if (countMove < AverageMoves) std::cout << " < ";
	else if (countMove > AverageMoves) std::cout << " > ";
	else std::cout << " = ";
	std::cout << AverageMoves << " (theoretical average count of moves)\n";
}