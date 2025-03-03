#include "Student.h"
#include <stdio.h>
#include <iostream>

void Student::SetName(const char* name, int size)
{
	this->name = new char[size+1];
	memcpy(this->name, name, size);
	this->name[size] = '\0';
}

const char* Student::GetName()
{
	return this->name;
}

void Student::SetMath(float gradeMath)
{
	this->math = gradeMath;
}

float Student::GetMath()
{
	return this->math;
}

void Student::SetEng(float gradeEng)
{
	this->eng = gradeEng;
}

float Student::GetEng()
{
	return this->eng;
}

void Student::SetHist(float gradeHist)
{
	this->hist = gradeHist;
}

float Student::GetHist()
{
	return this->hist;
}

float Student::GetAvg()	
{
	return (this->math + this->eng + this->hist) / 3.0;
}
