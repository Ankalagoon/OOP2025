#pragma once
#include <iostream>
#include <string>
class Materie {
protected:
	char nume[30];
	int nota;
public:
	Materie(char nume[],int nota);
	Materie();
	virtual char* GetName();
	virtual void SetName(char num[]);
	virtual int GetGrade();
	virtual void SetGrade(int x);
};