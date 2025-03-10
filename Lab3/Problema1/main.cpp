#include "Math.h"
#include <iostream>

using namespace std;

int main() {
	Math m;
	printf("%d\n", m.Add(2, 3));
	printf("%d\n", m.Add(2, 3, 4));
	printf("%d\n", m.Add(5.0, 6.1));
	printf("%d\n", m.Add(2.3, 9.0));
	printf("%d\n", m.Mul(4, 9));
	printf("%d\n", m.Mul(-4, 9, -2));
	printf("%d\n", m.Mul(4.0, 3.2));
	printf("%d\n", m.Mul(5.32, 9.14, 5.55));
	printf("%d\n", m.Add(5, 1, 2, 3, 4, 5));
	printf("%s\n", m.Add("123", "456"));
}