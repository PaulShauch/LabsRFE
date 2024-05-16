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
	Node* end;
	int size;
public:
	List();
	List(T value);
	List(const List& list);
	List& operator = (const List& list);
	List(List&& list);
	List& operator = (List&& list);
	void Delete();
	~List();
	void pushFront(T number);
	void pushBack(T number);
	void push(int position, T number);
	void popFront();
	void popBack();
	void pop(T value);
	int findEqual(T value);
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
	this->end = this->top;
	this->size = 1;
}

template <typename T>
List<T>::List(T value)
{
	this->top = new Node;
	this->top->value = value;
	this->top->sled = nullptr;
	this->top->pred = nullptr;
	this->end = this->top;
	this->size = 1;
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
	this->end = pthis;
	this->size = list.size;
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
	this->end = pthis;
	this->size = list.size;
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
	this->end = pthis;
	plist->value = 0;
	plist->pred = nullptr;
	plist->sled = nullptr;
	this->size = list.size;
	list.size = 0;
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
	this->end = pthis;
	plist->value = 0;
	plist->pred = nullptr;
	plist->sled = nullptr;
	this->size = list.size;
	list.size = 0;
	delete plist;
	return *this;
}

template <typename T>
void List<T>::Delete()
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
	this->size = 0;
	delete del;
}

template <typename T>
List<T>::~List()
{
	this->Delete();
}

template <typename T>
void List<T>::pushFront(T number)
{
	Node* po = new Node;
	po->value = number;
	po->sled = this->top;
	po->pred = nullptr;
	this->top = po;
	++this->size;
}

template <typename T>
void List<T>::pushBack(T number)
{
	Node* newNode = new Node;
	this->end->sled = newNode;
	newNode->value = number;
	newNode->sled = nullptr;
	newNode->pred = this->end;
	this->end = newNode;
	++this->size;
}

template <typename T>
void List<T>::push(int position, T number)
{
	if (position < 0 || position > size)
	{
		return;
	}
	if (position == 0)
	{
		pushFront(number);
		return;
	}
	if (position == size)
	{
		pushBack(number);
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
		point = point->sled;
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
		++this->size;
	}
}

template <typename T>
void List<T>::popFront()
{
	if (size <= 0) return;
	Node* del = this->top;
	this->top = this->top->sled;
	this->top->pred = nullptr;
	--this->size;
	del->value = 0;
	del->sled = nullptr;
	del->pred = nullptr;
	delete del;
}

template <typename T>
void List<T>::popBack()
{
	Node* del = this->end;
	this->end = this->end->pred;
	this->end->sled = nullptr;
	del->value = 0;
	del->sled = nullptr;
	del->pred = nullptr;
	delete del;
	--this->size;
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
		this->size--;
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
			this->size--;
			break;
		}
	}
}

template <typename T>
int List<T>::findEqual(T value)
{
	Node* point = top;
	int index = 0;
	if (!point) return -1;
	while (point->value != value)
	{
		if (!point->sled) break;
		point = point->sled;
		++index;
	}
	if (point->value == value)
	{
		return index;
	}
	else
	{
		return -1;
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
	if (position < 0 || position >= size)
	{
		return 0;
	}
	if (position <= size / 2)
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
	else
	{
		Node* pointer = this->end;
		int pos = this->size - 1;
		while (pos != position)
		{
			if (!pointer) return 0;
			pointer = pointer->pred;
			--pos;
		}
		return pointer->value;
	}
}