#include <stdio.h>
#include "MinArray.h"

bool compa(int x, int y) {
	return x < y;
}

int main(){
	int* ar = new int[3];
	ar[0] = 3;
	ar[1] = 1;
	ar[2] = 2;
	MinArray<int> a(3,ar);
	MinArray<int> b;
	b.Insert(10);
	b.Insert(20);
	b.Insert(4);
	a = a + b;
	a.Sort(compa);
	for (auto w : a) {
		cout << w << " ";
	}
	a = a - b;
	cout << "\n";
	for (auto w : a) {
		cout << w << " ";
	}
	return 0;
}