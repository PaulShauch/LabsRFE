#pragma once

using namespace std;

template <class T>
class List
{
private:
	struct Node
	{
		T value;
		Node* sled;
		Node* pred;
	};
	Node* top;
public:
	List();
	List(T value);
	List(const List& list);
	List& operator = (const List& list);
	List(List&& list);
	List& operator = (List&& list);
	~List();
	void push(int position, T number);
	void pop(T value);
	bool findEqual(T value);
	void print();
	T get(int position);
};

template <typename T>
List<T>::List()
{
	this->top = new Node;
	this->top->value = 0;
	this->top->sled = nullptr;
	this->top->pred = nullptr;
}

template <typename T>
List<T>::List(T value)
{
	this->top = new Node;
	this->top->value = value;
	this->top->sled = nullptr;
	this->top->pred = nullptr;
}

template <typename T>
List<T>::List(const List& list)
{
	Node* plist = list->top;
	Node* pthis = new Node;
	this->top = pthis;
	Node* buf = nullptr;
	while (plist->sled)
	{
		pthis->value = plist->value;
		pthis->pred = buf;
		buf = pthis;
		plist = plist->sled;
		pthis->sled = new Node;
		pthis = pthis->sled;
	}
	pthis->value = plist->value;
	pthis->pred = buf;
	pthis->sled = nullptr;
}

template <typename T>
List<T>& List<T>::operator = (const List& list)
{
	Node* plist = list->top;
	Node* pthis = new Node;
	this->top = pthis;
	Node* buf = nullptr;
	while (plist->sled)
	{
		pthis->value = plist->value;
		pthis->pred = buf;
		buf = pthis;
		plist = plist->sled;
		pthis->sled = new Node;
		pthis = pthis->sled;
	}
	pthis->value = plist->value;
	pthis->pred = buf;
	pthis->sled = nullptr;
	return *this;
}

template <typename T>
List<T>::List(List&& list)
{
	Node* plist = list->top;
	Node* pthis = new Node;
	this->top = pthis;
	Node* buf = nullptr;
	while (plist->sled)
	{
		pthis->value = plist->value;
		pthis->pred = buf;
		buf = pthis;
		Node* del = plist;
		del->value = 0;
		del->pred = nullptr;
		del->sled - nullptr;
		delete del;
		plist = plist->sled;
		pthis->sled = new Node;
		pthis = pthis->sled;
	}
	pthis->value = plist->value;
	pthis->pred = buf;
	pthis->sled = nullptr;
	plist->value = 0;
	plist->pred = nullptr;
	plist->sled = nullptr;
	delete plist;
}

template <typename T>
List<T>& List<T>::operator = (List&& list)
{
	Node* plist = list->top;
	Node* pthis = new Node;
	this->top = pthis;
	Node* buf = nullptr;
	while (plist->sled)
	{
		pthis->value = plist->value;
		pthis->pred = buf;
		buf = pthis;
		Node* del = plist;
		del->value = 0;
		del->pred = nullptr;
		del->sled - nullptr;
		delete del;
		plist = plist->sled;
		pthis->sled = new Node;
		pthis = pthis->sled;
	}
	pthis->value = plist->value;
	pthis->pred = buf;
	pthis->sled = nullptr;
	plist->value = 0;
	plist->pred = nullptr;
	plist->sled = nullptr;
	delete plist;
	return *this;
}

template <typename T>
List<T>::~List()
{
	Node* del = this->top;
	while (del->sled)
	{
		Node* delet = del;
		del = del->sled;
		delet->value = 0;
		delet->sled = nullptr;
		delet->pred = nullptr;
		delete delet;
	}
	del->value = 0;
	del->pred = nullptr;
	del->sled = nullptr;
	delete del;
}

template <typename T>
void List<T>::push(int position, T number)
{
	if (position == 0)
	{
		Node* po = new Node;
		po->value = number;
		po->sled = this->top;
		po->pred = nullptr;
		this->top = po;
		return;
	}
	int pos = 0;
	Node* point = top;
	bool is = true;
	while (pos != position - 1)
	{
		if (!point->sled)
		{
			point->sled = new Node;
			Node* buf = point;
			point = point->sled;
			point->value = number;
			point->sled = nullptr;
			point->pred = buf;
			is = false;
			break;
		}
		pos++;
	}
	if (is == true)
	{
		Node* psled = point->sled;
		point->sled = new Node;
		Node* poin = point->sled;
		poin->value = number;
		poin->sled = psled;
		poin->pred = point;
		if (psled) psled->pred = poin;
	}
}

template <typename T>
void List<T>::pop(T value)
{
	Node* point = top;
	if (point->value == value)
	{
		Node* pr = top;
		top = top->sled;
		top->pred = nullptr;
		pr->value = 0;
		pr->sled = nullptr;
		pr->pred = nullptr;
		delete pr;
		return;
	}
	while (point->sled)
	{
		point = point->sled;
		if (point->value == value)
		{
			point->value = 0;
			point->pred->sled = point->sled;
			point->sled->pred = point->pred;
			delete point;
			point->sled = nullptr;
			point->pred = nullptr;
			break;
		}
	}
}

template <typename T>
bool List<T>::findEqual(T value)
{
	Node* point = top;
	while (point->value != value)
	{
		if (!point->sled) break;
		point = point->sled;
	}
	if (point->value == value)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <typename T>
void List<T>::print()
{
	Node* point = top;
	while (point->sled)
	{
		cout << point->value << " ";
		point = point->sled;
	}
	cout << point->value << endl;
}

template <typename T>
T List<T>::get(int position)
{
	Node* pointer = this->top;
	int pos = 0;
	while (pos != position)
	{
		if (!pointer) return 0;
		pointer = pointer->sled;
		pos++;
	}
	return pointer->value;
}