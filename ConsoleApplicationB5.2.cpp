//Дан массив чисел произвольной длины.Отсортировать массив заданными методами:
//4. сортировкой простыми и бинарными вставками;
//Для тестирования программы заполнять массив значениями тремя способами:
//  по возрастанию, по убыванию, случайным образом.
//Каждый метод сортировки, каждый способ заполнения массивов оформить
//отдельными функциями.Функции оформить в виде отдельного файла.
//Для каждого метода сортировки определить число сравнений и перемещений
// (перестановок с одного места на другое) элементов в процессе выполнения программы.
//Сравнить экспериментальные результаты с известными теоретическими оценками этих показателей для
//  заданных методов сортировки.
//Обеспечить перегрузку и шаблоны необходимых функций для выполнения задания с типами элементов
//  массивов char, int, float, double.

#include <iostream>
#include <ctime>
#include "Functions.h"

int main()
{
	srand(time(NULL));
	const int N = 100;
	double array[N];
	enum class WayOfFill
	{
		Ascending=1, Descending, Random,
	};
	std::cout << "Choose way of fill:\n"
		<< (int)WayOfFill::Ascending << " - ascending\n"
		<< (int)WayOfFill::Descending << " - descending\n"
		<< (int)WayOfFill::Random << " - random\n";
	int n = 0;
	while (!(n >= (int)WayOfFill::Ascending && n <= (int)WayOfFill::Random))
	{
		std::cin >> n;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
		}
	}
	switch ((WayOfFill)n)
	{
	case WayOfFill::Ascending:
	{
		FillAscending(array, N);
		break;
	}
	case WayOfFill::Descending:
	{
		FillDescending(array, N);
		break;
	}
	case WayOfFill::Random:
	{
		FillRandom(array, N);
		break;
	}
	}
	std::cout << "original array:\n";
	for (int i = 0; i < N; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
	enum class WayOfSort
	{
		Simple = 1, Binary,
	};
	std::cout << "Choose way of sort:\n"
		<< (int)WayOfSort::Simple << " - simple insertion sort\n"
		<< (int)WayOfSort::Binary << " - binary insertion sort\n";
	n = 0;
	while (!(n >= (int)WayOfSort::Simple && n <= (int)WayOfSort::Binary))
	{
		std::cin >> n;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
		}
	}
	switch ((WayOfSort)n)
	{
	case WayOfSort::Simple:
	{
		SortInsertionSimple(array, N);
		break;
	}
	case WayOfSort::Binary:
	{
		SortInsertionBinary(array, N);
		break;
	}
	}
	std::cout << "sorted array:\n";
	for (int i = 0; i < N; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}