#include <iostream>

void FillAscending(char array[], const int N)
{
	for (int i = 0; i < N; i++)
	{
		array[i] = i + 1;
	}
}

void FillAscending(int array[], const int N)
{
	for (int i = 0; i < N; i++)
	{
		array[i] = i;
	}
}

void FillAscending(float array[], const int N)
{
	for (int i = 0; i < N; i++)
	{
		array[i] = 0.925637f * i + 1;
	}
}

void FillAscending(double array[], const int N)
{
	for (int i = 0; i < N; i++)
	{
		array[i] = 0.08323456 * i + 1.5;
	}
}

void FillDescending(char array[], const int N)
{
	for (int i = 0; i < N; i++)
	{
		array[i] = N - i;
	}
}

void FillDescending(int array[], const int N)
{
	for (int i = 0; i < N; i++)
	{
		array[i] = N - i - 1;
	}
}

void FillDescending(float array[], const int N)
{
	for (int i = 0; i < N; i++)
	{
		array[i] = N - 0.925637f * i + 1;
	}
}

void FillDescending(double array[], const int N)
{
	for (int i = 0; i < N; i++)
	{
		array[i] = N - 0.08323456 * i + 1.5;
	}
}

void FillRandom(char array[], const int N)
{
	for (int i = 0; i < N; i++)
	{
		array[i] = rand() % 128;
	}
}

void FillRandom(int array[], const int N)
{
	for (int i = 0; i < N; i++)
	{
		array[i] = rand() % 100;
	}
}

void FillRandom(float array[], const int N)
{
	for (int i = 0; i < N; i++)
	{
		array[i] = (float)rand() / rand() + rand() % 100;
	}
}

void FillRandom(double array[], const int N)
{
	for (int i = 0; i < N; i++)
	{
		array[i] = (double)rand() / rand() + rand() % 200 - 100;
	}
}