#include "Math.h"
#include <cstdarg>
#include <iostream>

int Math::Add(int x, int y)
{
	return x + y;
}

int Math::Add(int x, int y, int z)
{
	return x + y + z;
}

int Math::Add(double x, double y)
{
	return int(x + y);
}

int Math::Add(double x, double y, double z)
{
	return int(x + y + z);
}

int Math::Mul(int x, int y)
{
	return x * y;
}

int Math::Mul(int x, int y, int z)
{
	return x * y * z;
}

int Math::Mul(double x, double y)
{
	return int(x * y);
}

int Math::Mul(double x, double y, double z)
{
	return int(x * y * z);
}

int Math::Add(int count, ...)
{
	int val, sol = 0;
	va_list v;
	va_start(v, count);
	while (count--) {
		val = va_arg(v, int);
		sol += val;
	}
	va_end(v);
	return sol;
}

char* Math::Add(const char* x, const char* y)
{
	int c=0;
	int n=strlen(x);
	if (strlen(y) > n) n = strlen(y);
	char* z = new char[n+1];
	int i = 0, a, b;
	while (x[i] && y[i]) {
		if (x[i]) a = x[i];
		else a = '0';
		if (y[i]) b = y[i];
		else b = '0';
		z[i] = a + b + c - '0';
		c = 0;
		if (z[i] > '9') {
			z[i] -= 10;
			c = 1;
		}
		i++;
	}
	z[n] = '\0';
	return z;
}



