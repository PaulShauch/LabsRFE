//Квадратные матрицы(треугольные или симметричные) порядка n в целях
//экономии памяти задаются в виде одномерных массивов из(n + 1) * n / 2 чисел:
//сначала идёт n элементов первой строки, затем n – 1 элементов второй строки,
//начиная со второго элемента, и т.д. (из последней n - й строки берется только n - й
//элемент) или наоборот.
//4. Задана левая треугольная вещественная матрица А.Найти матрицу В = (А^2)T.

#include <iostream>
#include <iomanip>
#include <ctime>

int main()
{
    srand(time(NULL));
    const int n = 3;
    const int size = (n + 1) * n / 2;
    double A[size] = { 1,4,2,6,5,3 };
    for (int i = 0; i < size; i++)
    {
        A[i] = (double)rand() / rand() + rand() % 20 - 10;
    }
    for (int i = 0, j = 0; i < n;)
    {
        while (j <= i)
        {
            std::cout << std::setw(9) << A[(i + 1) * i / 2 + j] << " ";
            j++;
        }
        j = 0;
        std::cout << std::endl;
        i++;
    }
    std::cout << "\n\n\n";
    double C[size] = { 0 };
    for (int i = 0, j = 0; i < n;)
    {
        while (j <= i)
        {
            for (int l = j; l <= i; l++)
            {
                C[(i + 1) * i / 2 + j] += A[(i + 1) * i / 2 + l] * A[(l + 1) * l / 2 + j];
            }
            j++;
        }
        j = 0;
        i++;
    }
    for (int i = 0, j = 0; i < n;)
    {
        while (j <= i)
        {
            std::cout << std::setw(9) << C[(i + 1) * i / 2 + j] << " ";
            j++;
        }
        j = 0;
        std::cout << std::endl;
        i++;
    }
    std::cout << "\n\n\n";
    double B[size] = { 0 };
    for (int i = 0, j = i; i < n;)
    {
        while (j < n)
        {
            B[(2 * n - i + 1) * i / 2 + j - i] = C[(j + 1) * j / 2 + i];
            j++;
        }
        i++;
        j = i;
    }
    for (int i = 0, j = i; i < n;)
    {
        for (int k = 0; k < j; k++) std::cout << std::setw(10) << " ";
        while (j < n)
        {
            std::cout << std::setw(9) << B[(2 * n - i + 1) * i / 2 + j - i] << " ";
            j++;
        }
        std::cout << std::endl;
        i++;
        j = i;
    }
    return 0;
}