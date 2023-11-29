//Выполнить задание, оформив его через функции(ввода, вывода, сортировки).
//Передачу массива в функции организовать через указатели.
//Дана действительная матрица порядка n×m.Перебор строк / столбцов матрицы
//осуществить с использованием указателей.Обосновать выбор метода сортировки.
//4. Упорядочить столбцы по неубыванию последних элементов.

#include <iostream>
#include <iomanip>
#include <ctime>

void Fill(double* matrixPointer, const int N, const int M);

void Print(double* matrixPointer, const int N, const int M);

void Sort(double* matrixPointer, const int N, const int M);

int main()
{
    srand(time(NULL));
    const int N = 15;
    const int M = 10;
    double matrix[N][M] = { 0 };
    Fill(*matrix, N, M);
    std::cout << "original array:\n";
    Print(*matrix, N, M);
    Sort(*matrix, N, M);
    std::cout << "sorted array:\n";
    Print(*matrix, N, M);
    return 0;
}

void Fill(double* matrixPointer, const int N, const int M)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            *(matrixPointer + i * M + j) = (double)rand() / rand() + rand() % 200 - 100;
        }
    }
}

void Print(double* matrixPointer, const int N, const int M)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            std::cout << std::setw(10) << *(matrixPointer + i * M + j);
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Sort(double* matrixPointer, const int N, const int M)
{
    for (int j = 0; j < M - 1; j++)
    {
        double min = *(matrixPointer + (N - 1) * M + j);
        int indexMin = j;
        for (int k = j + 1; k < M; k++)
        {
            if (*(matrixPointer + (N - 1) * M + k) < min)
            {
                min = *(matrixPointer + (N - 1) * M + k);
                indexMin = k;
            }
        }
        for (int i = 0; i < N; i++)
        {
            double a = *(matrixPointer + i * M + indexMin);
            *(matrixPointer + i * M + indexMin) = *(matrixPointer + i * M + j);
            *(matrixPointer + i * M + j) = a;
        }
    }
}