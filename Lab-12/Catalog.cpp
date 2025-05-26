#include "Catalog.h"

Catalog::Catalog()
{
	this->nrs = 25;
	this->nrm = 3;
	this->stud = new Student[25];
	for (int i = 0;i < 25;i++) {
		this->stud[i] = Student(3);
	}
}

Catalog::Catalog(int nrs, int nrm)
{
	this->nrs = nrs;
	this->nrm = nrm;
	this->stud = new Student[nrs];
	for (int i = 0;i < nrs;i++) {
		this->stud[i] = Student(nrm);
		this->stud[i].SetNrMat(i);
	}
}

void Catalog::Rank(void(*swap)(Student& a, Student& b))
{
	for (int i = 0;i < this->nrs;i++) {
		for (int j = 0;j < this->nrs;j++) {
			int a, b;
			a = 0;
			for (int k = 0;k < this->stud[i].GetNrm();k++) a += this->stud[i].GetM(k).GetGrade();
			b = 0;
			for (int k = 0;k < this->stud[j].GetNrm();k++) b += this->stud[j].GetM(k).GetGrade();
			if (a > b) {
				/*
				Student Gigel;
				Gigel = this->stud[i];
				this->stud[i] = this->stud[j];
				this->stud[j] = Gigel;*/
				swap(this->stud[i], this->stud[j]);
			}
		}
	}
	PrintStud();
}

void Catalog::PrintStud()
{
	for (int i = 0;i < this->nrs;i++) {
		printf("%d ", this->stud[i].GetNrMat());
	}
}

void Catalog::SetStud(int poz,Student s)
{
	this->stud[poz] = s;
}

Student& Catalog::GetStud(int poz)
{
	return this->stud[poz];
}

int Catalog::GetNrs()
{
	return this->nrs;
}

int Catalog::GetNrm()
{
	return this->nrm;
}
