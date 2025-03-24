#pragma once
class Number
{
	char* value;
	int base,len;
public:
	Number(const char* value="0", int base = 10); // where base is between 2 and 16
	Number(int x, int base = 10);
	Number(Number& a);
	Number(Number&& a);
	~Number();

	// add operators and copy/move constructor

	friend Number operator+(Number a, Number b);
	friend Number operator-(Number a, Number b);
	bool operator>(Number b);
	bool operator<(Number b);
	bool operator>=(Number b);
	bool operator<=(Number b);
	bool operator==(Number b);
	void operator+=(Number b);
	void operator--();
	void operator--(int);
	void operator=(Number b);
	void operator=(int x);
	char operator[](int index);

	int Convert10();
	void ConvertBack(int val,int baza);
	void SwitchBase(int newBase);
	void Print();
	char*  GetValue(); // returns the number of digits for the current number
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
	void KillValue();
};

