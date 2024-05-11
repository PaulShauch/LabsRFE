#pragma once

using namespace std;

template <class T>
class ForwardList
{
private:
	struct Node
	{
		T value;
		Node* p;
	};
	Node* top;
public:
	ForwardList();
	ForwardList(T value);
	ForwardList(const ForwardList& list);
	ForwardList& operator = (const ForwardList& list);
	ForwardList(ForwardList&& list);
	ForwardList& operator = (ForwardList&& list);
	~ForwardList();
	void push(int position, T number);
	void pop(T value);
	bool findEqual(T value);
	void print();
};

template <typename T>
ForwardList<T>::ForwardList()
{
	this->top = new Node;
	this->top->value = 0;
	this->top->p = nullptr;
}

template <typename T>
ForwardList<T>::ForwardList(T value)
{
	this->top = new Node;
	this->top->value = value;
	this->top->p = nullptr;
}

template <typename T>
ForwardList<T>::ForwardList(const ForwardList& list)
{
	Node* plist = &list;
	Node* pthis = new Node;
	while (plist->p)
	{
		pthis->value = plist->value;
		plist = plist->p;
		pthis->p = new Node;
		pthis = pthis->p;
	}
	pthis->value = plist->value;
	pthis->p = nullptr;
}

template <typename T>
ForwardList<T>& ForwardList<T>::operator = (const ForwardList& list)
{
	Node* plist = &list;
	Node* pthis = new Node;
	while (plist->p)
	{
		pthis->value = plist->value;
		plist = plist->p;
		pthis->p = new Node;
		pthis = pthis->p;
	}
	pthis->value = plist->value;
	pthis->p = nullptr;
	return *this;
}

template <typename T>
ForwardList<T>::ForwardList(ForwardList&& list)
{
	Node* plist = &list.top;
	Node* pthis = new Node;
	this->top = pthis;
	while (plist->p)
	{
		pthis->value = plist->value;
		Node* del = plist;
		plist = plist->p;
		del->value = 0;
		del->p = nullptr;
		delete del;
		pthis->p = new Node;
		pthis = pthis->p;
	}
	pthis->value = plist->value;
	pthis->p = nullptr;
	plist->value = 0;
	delete plist;
}

template <typename T>
ForwardList<T>& ForwardList<T>::operator = (ForwardList&& list)
{
	Node* plist = &list.top;
	Node* pthis = new Node;
	this->top = pthis;
	while (plist->p)
	{
		pthis->value = plist->value;
		Node* del = plist;
		plist = plist->p;
		del->value = 0;
		del->p = nullptr;
		delete del;
		pthis->p = new Node;
		pthis = pthis->p;
	}
	pthis->value = plist->value;
	pthis->p = nullptr;
	plist->value = 0;
	delete plist;
	return *this;
}

template <typename T>
ForwardList<T>::~ForwardList()
{
	Node* del = this->top;
	while (del->p)
	{
		Node* delet = del;
		del = del->p;
		delet->value = 0;
		delet->p = nullptr;
		delete delet;
	}
	del->value = 0;
	delete del;
}

template <typename T>
void ForwardList<T>::push(int position, T number)
{
	if (position == 0)
	{
		Node* po = new Node;
		po->value = number;
		po->p = this->top;
		this->top = po;
		return;
	}
	int pos = 0;
	Node* point = top;
	bool is = true;
	while (pos != position - 1)
	{
		if (!point->p)
		{
			point->p = new Node;
			point = point->p;
			point->value = number;
			point->p = nullptr;
			is = false;
			break;
		}
		pos++;
	}
	if (is == true)
	{
		Node* pointer = point->p;
		point->p = new Node;
		Node* poin = point->p;
		poin->value = number;
		poin->p = pointer;
	}
}

template <typename T>
void ForwardList<T>::pop(T value)
{
	Node* point = top;
	if (point->value == value)
	{
		Node* pred = top;
		top = top->p;
		pred->value = 0;
		pred->p = nullptr;
		delete pred;
		return;
	}
	while (point->p)
	{
		Node* pred = point;
		point = point->p;
		if (point->value == value)
		{
			pred->p = point->p;
			point->value = 0;
			delete point;
			break;
		}
	}
}

template <typename T>
bool ForwardList<T>::findEqual(T value)
{
	Node* point = top;
	while (point->value != value)
	{
		if (!point->p) break;
		point = point->p;
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
void ForwardList<T>::print()
{
	Node* point = top;
	while (point->p)
	{
		cout << point->value << " ";
		point = point->p;
	}
	cout << point->value << endl;
}