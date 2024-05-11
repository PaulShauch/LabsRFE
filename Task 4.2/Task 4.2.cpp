//8. Описать функцию, которая формирует список символов L, включив в него
//по одному разу элементы, которые входят в список L1 и не входят в список L2.

#include <iostream>
#include "ForwardList.h"

using namespace std;

void function(ForwardList<char>& L1, ForwardList<char>& L2, ForwardList<char>& L)
{
	for (int i = -128; i < 128; i++)
	{
		if (L1.findEqual(i) && !L2.findEqual(i))
		{
			L.push(0, i);
		}
	}
}

int main()
{
	const int N = 10;
	ForwardList<char> L1(rand() % N + 64);
	for (int i = 1; i < N; i++)
	{
		L1.push(i, rand() % N + 64);
	}
	L1.print();
	ForwardList<char> L2(rand() % N + 64);
	for (int i = 1; i < N; i++)
	{
		L2.push(i, rand() % N + 64);
	}
	L2.print();
	ForwardList<char> L(0);
	L.pop(0);
	function(L1, L2, L);
	L.print();
	return 0;
}