#include "Math.h"

int Math::GetGrade()
{
	return this->nota;
}

void Math::SetGrade(int x)
{
	this->nota = x;
}

char* Math::GetName()
{
	return this->nume;
}

void Math::SetName(char num[])
{
	strcpy_s(this->nume, num);
}
