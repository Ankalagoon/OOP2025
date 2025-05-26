#include "Materie.h"

Materie::Materie(char nume[], int nota)
{
	strcpy_s(this->nume, nume);
	this->nota = nota;
}

Materie::Materie()
{
	strcpy_s(this->nume, "nume");
	this->nota = 0;
}

char* Materie::GetName()
{
	return this->nume;
}

void Materie::SetName(char num[])
{
	strcpy_s(this->nume, num);
}

int Materie::GetGrade()
{
	return this->nota;
}

void Materie::SetGrade(int x)
{
	this->nota = x;
}
