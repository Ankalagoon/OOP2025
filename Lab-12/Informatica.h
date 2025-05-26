#pragma once
#include "Materie.h"
class Informatica : public Materie
{
public:
	Informatica(char nume[], int nota) : Materie(nume, nota) {
	};
	int GetGrade();
	void SetGrade(int x);
	char* GetName();
	void SetName(char num[]);
};

