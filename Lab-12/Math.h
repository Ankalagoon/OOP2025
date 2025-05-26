#pragma once
#include "Materie.h"
class Math : public Materie
{
public:
	Math(char nume[], int nota) : Materie(nume, nota) {
	};
	int GetGrade();
	void SetGrade(int x);
	char* GetName();
	void SetName(char num[]);
};

