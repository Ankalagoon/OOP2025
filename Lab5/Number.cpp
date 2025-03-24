#include "Number.h"
#include <iostream>

Number::Number(const char* value, int base)
{
	int i = 0;
	while (value[i] != NULL) i++;
	this->value = new char[i+1];
	memcpy(this->value , value, i);
	this->value[i] = '\0';
	this->len = i;
	this->base = base;
}

Number::Number(int x, int base)
{
	this->value = new char;
	ConvertBack(x, base);
}

Number::Number(Number& a)
{
	this->value = a.GetValue();
	this->base = a.GetBase();
	this->len = a.GetDigitsCount();
}

Number::Number(Number&& a)
{
	this->value = a.GetValue();
	a.KillValue();
	this->base = a.GetBase();
	this->len = a.GetDigitsCount();
}

Number::~Number()
{
	///delete this->value;
	///this->base = NULL;
}

bool Number::operator>(Number b)
{
	return this->Convert10() > b.Convert10();
}

bool Number::operator<(Number b)
{
	return this->Convert10() < b.Convert10();
}

bool Number::operator>=(Number b)
{
	return this->Convert10() >= b.Convert10();
}

bool Number::operator<=(Number b)
{
	return this->Convert10() <= b.Convert10();
}

bool Number::operator==(Number b)
{
	return this->Convert10() == b.Convert10();
}

void Number::operator+=(Number b)
{
	int baz;
	baz = this->GetBase();
	if (baz < b.GetBase()) baz = b.GetBase();
	this->ConvertBack(this->Convert10() + b.Convert10(), baz);
}

void Number::operator--()
{
	int i;
	for (i = 0;i < this->len;i++) {
		this->value[i] = this->value[i + 1];
	}
	this->len--;
}

void Number::operator--(int)
{
	this->value[this->len-1] = this->value[this->len - 0];
	this->len--;
}

void Number::operator=(Number b)
{
	this->ConvertBack(b.Convert10(), b.GetBase());
}

void Number::operator=(int x)
{
	this->ConvertBack(x, this->base);
}

char Number::operator[](int index)
{
	return this->value[index];
}

int Number::Convert10()
{
	int x = 0,i;
	for (i = 0;i < this->len;i++) {
		x *= this->base;
		x += this->value[i]-'0'- ((this->value[i]-'0') > 9)*7;
		///printf("#%d#\n", x);
		///printf("%d ",x);
	}
	return x;
}

void Number::ConvertBack(int val,int baza)
{
	char* num = new char[100];
	char c;
	int n = 0,i;
	while (val > 0) {
		num[n]= (val% baza)+'0'+((val % baza) >9)*7;
		val /= baza;
		n++;
	}
	n--;
	for (i = 0;i <= n/2;i++) {
		c = num[i];
		num[i] = num[n - i];
		num[n - i] = c;	
	}
	n++;
	num[n] = '\0';
	memcpy(this->value, num, n);
	this->value[n] = '\0';
	this->base = baza;
	this->len = n;
}

void Number::SwitchBase(int newBase)
{
	int x = this->Convert10();
	///printf("|%d|\n", x);
	this->ConvertBack(x, newBase);
}

void Number::Print()
{
	printf("Numar: %s | Baza: %d \n",this->value, this->base);
}

char* Number::GetValue()
{
	return this->value;
}

int Number::GetDigitsCount()
{
	return this->len;
}

int Number::GetBase()
{
	return this->base;
}

void Number::KillValue()
{
	this->value = nullptr;
}

Number operator+(Number a, Number b)
{
	Number c("1");
	int baz=0;
	baz = a.GetBase();
	if (baz < b.GetBase()) baz = b.GetBase();
	c.ConvertBack(a.Convert10() + b.Convert10(), baz);
	return c;
}

Number operator-(Number a, Number b)
{
	Number c("1");
	int baz;
	baz = a.GetBase();
	if (baz < b.GetBase()) baz = b.GetBase();
	c.ConvertBack(a.Convert10() - b.Convert10(), baz);
	return c;
}