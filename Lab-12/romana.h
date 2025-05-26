#pragma once
#include "Materie.h"
class Romana : public Materie
{
public:
	Romana(char nume[], int nota) : Materie(nume, nota) {
	};
	int GetGrade();
	void SetGrade(int x);
	char* GetName();
	void SetName(char num[]);
};


