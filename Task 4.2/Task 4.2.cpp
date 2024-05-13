//8. Описать функцию, которая формирует список символов L, включив в него
//по одному разу элементы, которые входят в список L1 и не входят в список L2.

#include <iostream>
#include "ForwardList.h"

using namespace std;

void function(ForwardList<char>& L1, ForwardList<char>& L2, ForwardList<char>& L)
{
	int i = 0;
	int n = 0;
	while (L1.get(i))
	{
		char value = L1.get(i);
		if (L2.findEqual(value) < 0 && L.findEqual(value) < 0)
		{
			L.push(n, value);
			++n;
		}
		i++;
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