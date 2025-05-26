#pragma once
#include "Student.h"
class Catalog
{
	int nrs;
	int nrm;
	Student* stud;
public:
	Catalog();
	Catalog(int nrs,int nrm);
	virtual void Rank(void(*swap)(Student& a, Student& b));
	virtual void PrintStud();
	virtual void SetStud(int poz,Student s);
	virtual Student& GetStud(int poz);
	virtual int GetNrs();
	virtual int GetNrm();
};

