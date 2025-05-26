#include "Informatica.h"

int Informatica::GetGrade()
{
	return this->nota;
}

void Informatica::SetGrade(int x)
{
	this->nota = x;
}

char* Informatica::GetName()
{
	return this->nume;
}

void Informatica::SetName(char num[])
{
	strcpy_s(this->nume, num);
}
