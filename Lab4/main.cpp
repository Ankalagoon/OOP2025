#include "Sort.h"
#include <stdio.h>
using namespace std;

int main() {
	int* v[4] = {new int(3),new int(5),new int(1),new int(6)};
	Sort a(10, 50, 200);
	Sort b = { 4,2,3,1,5 };
	Sort c(3, v);
	Sort d(6, 9, 33, 11, 22, 5, 2);
	Sort e(5, "10,3,2,1,5");
	a.InsertSort();
	a.Print();
	b.QuickSort();
	b.Print();
	c.BubbleSort();
	c.Print();
	d.QuickSort();
	d.Print();
	printf("%d | %d \n", e.GetElementFromIndex(3), e.GetElementsCount());
	e.BubbleSort();
	e.Print();
}