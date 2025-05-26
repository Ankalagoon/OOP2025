#include "romana.h"

int Romana::GetGrade()
{
	return this->nota;
}

void Romana::SetGrade(int x)
{
	this->nota = x;
}

char* Romana::GetName()
{
	return this->nume;
}

void Romana::SetName(char num[])
{
	strcpy_s(this->nume, num);
}
