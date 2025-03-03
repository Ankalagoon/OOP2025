#pragma once
class Student
{
	char* name;
	float math;
	float eng;
	float hist;
public:
	void SetName(const char* name, int size);
	const char* GetName();
	void SetMath(float gradeMath);
	float GetMath();
	void SetEng(float gradeEng);
	float GetEng();
	void SetHist(float gradeHist);
	float GetHist();
	float GetAvg();
};

