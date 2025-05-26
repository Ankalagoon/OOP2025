#include "Student.h"

Student::Student(int m)
{
	this->nrm = m;
	this->NrMat = 0;
	this->mat = new Materie[m];
}

Student::Student()
{
	this->nrm = 3;
	this->NrMat = 0;
	this->mat = new Materie[3];
}

void Student::AddM(Materie x)
{
	this->mat[this->nrm] = x;
	this->nrm++;
}

Materie& Student::GetM(int poz)
{
	return this->mat[poz];
}

void Student::SetM(int poz, Materie x)
{
	this->mat[poz] = x;
}

int Student::GetNrm()
{
	return this->nrm;
}

void Student::SetNrm(int x)
{
	this->nrm = x;
}

int Student::GetNrMat()
{
	return this->NrMat;
}

void Student::SetNrMat(int x)
{
	this->NrMat = x;
}
