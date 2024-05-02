#pragma once

using namespace std;

template <class T>
class Vector
{
	friend istream& operator >> (istream&, Vector<T>&);
	friend ostream& operator << (ostream&, Vector<T>&);
private:
	T* array;
	int size;
	int amount;
public:
	Vector();
	Vector(int size);
	Vector(int size, T value);
	Vector(const Vector& massiv);
	Vector& operator = (const Vector& massiv);
	Vector(Vector&& massiv);
	Vector& operator = (Vector&& massiv);
	~Vector();
	int amountOfNumbers();
	void fillRandom();
	T& operator [] (const int i);
	const T& operator [] (const int i) const;
	void fillByUser();
	void pushBack(T number);
	void push(int position, T number);
	bool isEmpty();
	void popBack();
};

template <typename T>
Vector<T>::Vector()
{
	this->size = 0;
	this->amount = 0;
	this->array = new T[0];
}

template <typename T>
Vector<T>::Vector(int size)
{
	this->size = size;
	this->amount = size;
	this->array = new T[size];
	for (int i = 0; i < size; i++)
	{
		this->array[i] = 0;
	}
}

template <typename T>
Vector<T>::Vector(int size, T value)
{
	this->size = size;
	this->amount = size;
	this->array = new T[size];
	for (int i = 0; i < size; i++)
	{
		this->array[i] = value;
	}
}

template <typename T>
Vector<T>::Vector(const Vector& massiv)
{
	this->size = massiv.size;
	this->amount = massiv.amount;
	this->array = new T[this->size];
	for (int i = 0; i < this->amount; i++)
	{
		this->array[i] = massiv.array[i];
	}
}

template <typename T>
Vector<T>& Vector<T>::operator = (const Vector& massiv)
{
	this->size = massiv.size;
	this->amount = massiv.amount;
	for (int i = 0; i < this->amount; i++)
	{
		this->array[i] = massiv.array[i];
	}
	return *this;
}

template <typename T>
Vector<T>::Vector(Vector&& massiv)
{
	this->size = massiv.size;
	this->amount = massiv.amount;
	this->array = new T[this->size];
	for (int i = 0; i < this->amount; i++)
	{
		this->array[i] = massiv.array[i];
	}
	delete[] massiv.array;
	massiv.array = nullptr;
	massiv.size = 0;
	massiv.amount = 0;
}

template <typename T>
Vector<T>& Vector<T>::operator = (Vector&& massiv)
{
	this->size = massiv.size;
	this->amount = massiv.amount;
	for (int i = 0; i < this->amount; i++)
	{
		this->array[i] = massiv.array[i];
	}
	delete[] massiv.array;
	massiv.array = nullptr;
	massiv.size = 0;
	massiv.amount = 0;
	return *this;
}

template <typename T>
Vector<T>::~Vector()
{
	delete[] this->array;
}

template <typename T>
int Vector<T>::amountOfNumbers()
{
	return this->amount;
}

template <typename T>
void Vector<T>::fillRandom()
{
	for (int i = 0; i < this->amount; i++)
	{
		this->array[i] = rand() % this->size + (double)rand() / rand();
	}
}

template <typename T>
T& Vector<T>::operator [] (const int i)
{
	if (i < 0 || i >= this->amount)
	{
		T element = 0;
		return element;
	}
	return this->array[i];
}

template <typename T>
const T& Vector<T>::operator [] (const int i) const
{
	if (i < 0 || i >= this->amount)
	{
		T element = 0;
		return element;
	}
	return this->array[i];
}

template <typename T>
void Vector<T>::fillByUser()
{
	for (int i = 0; i < this->amount; i++)
	{
		cin >> this->array[i];
	}
}

template <typename T>
void Vector<T>::pushBack(T number)
{
	if (this->amount >= this->size)
	{
		this->size = this->size * 2 + 1;
		T* arr = new T[this->size];
		for (int i = 0; i < this->amount; i++)
		{
			arr[i] = this->array[i];
		}
		arr[this->amount] = number;
		delete[] this->array;
		this->array = arr;
		this->amount++;
	}
	else
	{
		this->array[this->amount] = number;
		this->amount++;
	}
}

template <typename T>
void Vector<T>::push(int position, T number)
{
	if (position > this->amount && position < 0)
	{
		cout << "error position\n";
		return;
	}
	if (this->amount >= this->size)
	{
		this->size = this->size * 2 + 1;
		T* arr = new T[this->size];
		for (int i = 0; i < position; i++)
		{
			arr[i] = this->array[i];
		}
		arr[position] = number;
		for (int i = position + 1; i <= this->amount; i++)
		{
			arr[i] = this->array[i - 1];
		}
		delete[] this->array;
		this->array = arr;
		this->amount++;
	}
	else
	{
		T bufin = this->array[position];
		T bufout = bufin;
		this->array[position] = number;
		for (int i = position + 1; i <= this->amount; i++)
		{
			bufout = this->array[i];
			this->array[i] = bufin;
			bufin = bufout;
		}
		this->amount++;
	}
}

template <typename T>
bool Vector<T>::isEmpty()
{
	bool is = false;
	if (this->amount == 0)
	{
		is = true;
	}
	return is;
}

template <typename T>
void Vector<T>::popBack()
{
	if (this->isEmpty())
	{
		cout << "vector is empty\n";
		return;
	}
	this->array[this->amount - 1] = 0;
	this->amount--;
}

template<typename T>
istream& operator >> (istream& in, Vector<T>& vector)
{
	for (int i = 0; i < vector.amount; i++)
	{
		in >> vector.array[i];
	}
	return in;
}

template<typename T>
ostream& operator << (ostream& out, Vector<T>& vector)
{
	for (int i = 0; i < vector.amount; i++)
	{
		out << vector.array[i] << " ";
	}
	out << endl;
	return out;
}