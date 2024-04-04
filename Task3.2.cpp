//Выполнить задания для бинарного файла.Задания выполнить через функции.Размер файлов <= 64GiB
//8. В файлах f и g содержатся вещественные числа, упорядоченные по возрастанию.
//Получить за один проход файл чисел, встречающихся в обоих исходных файлах без повторений

#include <stdlib.h>
#include <fstream>
#include <iostream>
using namespace std;

void create(ofstream&, int);
void read_file(ifstream&);
void findNoRepeatedElements(ofstream&, ifstream&, ifstream&);

int main()
{
	int n;
	cout << "enter n" << endl; cin >> n;
	ofstream outfile("file.bin", ios::binary);
	if (!outfile)
	{
		cout << "error1" << endl;
		return 1;
	}
	create(outfile, n);
	outfile.close();
	ifstream infile("file.bin", ios::binary);
	if (!infile)
	{
		cout << "error2" << endl;
		return 2;
	}
	read_file(infile);
	infile.close();
	cout << "enter n" << endl; cin >> n;
	ofstream outfile0("file0.bin", ios::binary);
	if (!outfile0)
	{
		cout << "error1" << endl;
		return 1;
	}
	create(outfile0, n);
	outfile0.close();
	ifstream infile0("file0.bin", ios::binary);
	if (!infile0)
	{
		cout << "error2" << endl;
		return 2;
	}
	read_file(infile0);
	infile0.close();
	ofstream outfile_new("file1.bin", ios::binary);
	if (!outfile_new)
	{
		cout << "error3" << endl;
		return 3;
	}
	infile.clear();
	infile.open("file.bin", ios::binary);
	if (!infile)
	{
		cout << "error4" << endl;
		return 4;
	}
	infile0.clear();
	infile0.open("file0.bin", ios::binary);
	if (!infile0)
	{
		cout << "error4" << endl;
		return 4;
	}
	findNoRepeatedElements(outfile_new, infile, infile0);
	outfile_new.close();
	infile.close();
	infile.clear();
	infile.open("file1.bin", ios::binary);
	if (!infile)
	{
		cout << "error5" << endl;
		return 5;
	}
	read_file(infile);
	infile.close();
	return 0;
}

void create(ofstream& outfile, int n)
{
	for (int i = 1; i <= n; i++)
	{
		double v;
		std::cout << "enter " << i << " double number: ";
		std::cin >> v;
		outfile.write(reinterpret_cast <char*> (&v), sizeof(double));
	}
}

void read_file(ifstream& infile)
{
	double v;
	while (infile.read(reinterpret_cast <char*> (&v), sizeof(double)))
	{
		cout << v << " ";
	}
}

void findNoRepeatedElements(ofstream& outfile_new, ifstream& infile1, ifstream& infile2)
{
	bool is = false;
	bool is2 = false;
	double buf;
	double buf1;
	double buf2;
	double now1;
	infile1.read(reinterpret_cast <char*> (&now1), sizeof(double));
	double pred1 = now1 - 1;
	double sled1 = now1 - 1;
	if (infile1.read(reinterpret_cast <char*> (&buf1), sizeof(double)))
	{
		sled1 = buf1;
	}
	double now2;
	infile2.read(reinterpret_cast <char*> (&now2), sizeof(double));
	double pred2 = now2 - 1;
	double sled2 = now2 - 1;
	if (infile2.read(reinterpret_cast <char*> (&buf2), sizeof(double)))
	{
		sled2 = buf2;
	}
	while (infile1 || infile2)
	{
		is = true;
		if (now1 < now2 && infile1)
		{
			if (infile1.read(reinterpret_cast <char*> (&buf1), sizeof(double)))
			{
				pred1 = now1;
				now1 = sled1;
				sled1 = buf1;
			}
		}
		else if (now1 > now2 && infile2)
		{
			if (infile2.read(reinterpret_cast <char*> (&buf2), sizeof(double)))
			{
				pred2 = now2;
				now2 = sled2;
				sled2 = buf2;
			}
		}
		else
		{
			if (now1 == now2 && now1 != sled1 && now2 != sled2 && now1 != pred1 && now2 != sled2)
			{
				outfile_new.write(reinterpret_cast <char*> (&now1), sizeof(double));
				buf = now1;
				is2 = true;
			}
			if (infile1.read(reinterpret_cast <char*> (&buf1), sizeof(double)))
			{
				pred1 = now1;
				now1 = sled1;
				sled1 = buf1;
			}
			if (infile2.read(reinterpret_cast <char*> (&buf2), sizeof(double)))
			{
				pred2 = now2;
				now2 = sled2;
				sled2 = buf2;
			}
		}
	}
	if (now1 == now2)
	{
		if (!is)
		{
			outfile_new.write(reinterpret_cast <char*> (&now1), sizeof(double));
		}
		else if (is2 && now1 != buf && now1 != sled1 && now1 != sled2 && now1 != pred1 && now1 != pred2)
		{
			outfile_new.write(reinterpret_cast <char*> (&now1), sizeof(double));
		}
	}
	else if (now1 == sled2 && sled2 > now2 && now1 != sled1)
	{
		outfile_new.write(reinterpret_cast <char*> (&pred1), sizeof(double));
	}
	else if (sled1 == now2 && sled1 > now1 && now2 != sled2)
	{
		outfile_new.write(reinterpret_cast <char*> (&now2), sizeof(double));
	}
	if (sled1 == sled2 && sled1 > now1 && sled2 > now2)
	{
		outfile_new.write(reinterpret_cast <char*> (&sled1), sizeof(double));
	}
}