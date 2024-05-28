//Написать программу для работы с базой данных, содержащей записи со сведениями о студентах :
//ФИО, возраст, пол, курс, успеваемость, в которой должны выполняться следующие действия :
//создание файла, просмотр файла.
//Выполнить задания для бинарного файла.Размер файлов <= 64GiB.
//8. По исходному файлу определить всех неуспевающих студентов.Сформировать файл из этих студентов.

#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;

const int MagicNumber = 64;

struct Student
{
	char FIO[MagicNumber];
	int age;
	bool sex;
	int course;
	double srball;
};

bool compare(const char*, const char*);
void add_student(ofstream&);
void create(ofstream&);
void read_file(ifstream&);
void change_student(fstream&);
void neusp_students(ofstream&, ifstream&);
void delete_student(fstream&);

int main()
{
	ofstream outfile("file.bin", ios::binary);
	if (!outfile)
	{
		cout << "error1" << endl;
		return 1;
	}
	create(outfile);
	outfile.close();
	cout << "\n";
	ifstream infile("file.bin", ios::binary);
	if (!infile)
	{
		cout << "error2" << endl;
		return 2;
	}
	read_file(infile);
	infile.close();
	fstream file("file.bin", ios::out | ios::in | ios::binary);
	if (!file)
	{
		cout << "error5" << endl;
		return 5;
	}
	std::cout << "Deleting student:\n";
	delete_student(file);
	file.close();
	std::cout << "After deleting:\n\n";
	infile.open("file.bin", ios::binary);
	read_file(infile);
	infile.close();
	file.open("file.bin", ios::out | ios::in | ios::binary);
	std::cout << "Changing student:\n";
	change_student(file);
	file.close();
	std::cout << "After changing:\n\n";
	infile.open("file.bin", ios::binary);
	read_file(infile);
	infile.close();
	outfile.open("file_new.bin", ios::binary);
	if (!outfile)
	{
		cout << "error3" << endl;
		return 3;
	}
	infile.open("file.bin", ios::binary);
	neusp_students(outfile, infile);
	outfile.close();
	infile.close();
	infile.open("file_new.bin", ios::binary);
	if (!infile)
	{
		cout << "error4" << endl;
		return 4;
	}
	std::cout << "NEUSP STUDENTS:\n\n";
	read_file(infile);
	infile.close();
	return 0;
}

bool compare(const char* a, const char* b)
{
	bool is = true;
	for (int i = 0; *(a + i) != 0 && *(b + i) != 0; i++)
	{
		if (*(a + i) != *(b + i))
		{
			is = false;
		}
	}
	return is;
}

void add_student(ofstream& outfile)
{
	Student student;
	cout << "Enter FIO:\n";
	std::cin.getline(student.FIO, MagicNumber);
	cout << "Enter age:\n";
	std::cin >> student.age;
	cout << "Enter sex:\n";
	int sex; std::cin >> sex;
	student.sex = (bool)sex;
	cout << "Enter course:\n";
	std::cin >> student.course;
	cout << "Enter srball\n";
	std::cin >> student.srball;
	outfile.write(reinterpret_cast <char*> (&student), sizeof(Student));
}

void create(ofstream& outfile)
{
	while (true)
	{
		add_student(outfile);
		cout << "Enter another student?(0 - No):\n";
		int x; std::cin >> x;
		std::cin.ignore(32767, '\n');
		if (!x) break;
	}
}

void read_file(ifstream& infile)
{
	Student student;
	while (infile.read(reinterpret_cast <char*> (&student), sizeof(Student)))
	{
		if (!compare(student.FIO, "deleted"))
		{
			cout << student.FIO << "\nage: " << student.age << "\n";
			if (student.sex)
			{
				cout << "boy\n";
			}
			else
			{
				cout << "girl\n";
			}
			cout << "course: " << student.course << "\nsrball: " << student.srball << "\n\n";
		}
	}
}

void change_student(fstream& file)
{
	cout << "Enter FIO of student:\n";
	char* fio = new char[MagicNumber];
	std::cin.getline(fio, MagicNumber);
	Student student;
	bool is = false;
	while (file.read(reinterpret_cast <char*> (&student), sizeof(Student)))
	{
		if (compare(student.FIO, fio))
		{
			is = true;
			cout << "What you want to change:\n1 - FIO\n2 - age\n3 - sex\n4 - course\n5-srball\nany other number - nothing\n";
			int x; std::cin >> x;
			switch (x)
			{
			case 1:
				cout << "Enter new FIO\n";
				std::cin.clear();
				std::cin.ignore(32767, '\n');
				std::cin.getline(fio, MagicNumber);
				for (int i = 0; i < MagicNumber; i++)
				{
					*(student.FIO + i) = *(fio + i);
				}
				break;
			case 2:
				cout << "Enter  new age: ";
				int a; std::cin >> a;
				student.age = a;
				break;
			case 3:
				cout << "Enter new sex: ";
				bool s; std::cin >> s;
				student.sex = s;
				break;
			case 4:
				cout << "Enter new course: ";
				int c; std::cin >> c;
				student.course = c;
				break;
			case 5:
				cout << "Enter new sr ball: ";
				double sr; std::cin >> sr;
				student.srball = sr;
				break;
			}
			auto pos = file.tellg();
			pos -= sizeof(Student);
			file.seekp(pos);
			file.write(reinterpret_cast <char*> (&student), sizeof(Student));
			break;
		}
	}
	if (!is) cout << "Student not found\n";
	delete[] fio;
}

void neusp_students(ofstream& outfile, ifstream& infile)
{
	Student student;
	while (infile.read(reinterpret_cast <char*> (&student), sizeof(Student)))
	{
		if (student.srball < 4 && !compare(student.FIO, "deleted"))
		{
			outfile.write(reinterpret_cast <char*> (&student), sizeof(Student));
		}
	}
}

void delete_student(fstream& file)
{
	cout << "Enter FIO of student:\n";
	char* fio = new char[MagicNumber];
	std::cin.getline(fio, MagicNumber);
	Student student;
	bool is = false;
	while (file.read(reinterpret_cast <char*> (&student), sizeof(Student)))
	{
		if (compare(student.FIO, fio))
		{
			is = true;
			auto pos = file.tellg();
			pos -= sizeof(Student);
			file.seekp(pos);
			Student deleted{ "deleted" };
			file.write(reinterpret_cast <char*> (&deleted), sizeof(Student));
			break;
		}
	}
	if (!is) cout << "Student not found\n";
	delete[] fio;
}