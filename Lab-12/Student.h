#pragma once
#include "Materie.h"
class Student
{
	int NrMat;
	int nrm;
	Materie* mat;
public:
	Student(int m);
	Student();
	void AddM(Materie x);
	Materie& GetM(int poz);
	void SetM(int poz,Materie x);
	int GetNrm();
	void SetNrm(int x);
	int GetNrMat();
	void SetNrMat(int x);
};

