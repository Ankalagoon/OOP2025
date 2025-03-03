#include "FunctiiGlobale.h"
#include <iostream>

int compareName(Student* A, Student* B,int size)
{
	return memcmp(A->GetName(), B->GetName(),size);
}

int compareMath(Student* A, Student* B)
{
	if (A->GetMath() > B->GetMath()) return 1;
	if (A->GetMath() < B->GetMath()) return -1;
	return 0;
}

int compareEng(Student* A, Student* B)
{
	if (A->GetEng() > B->GetEng()) return 1;
	if (A->GetEng() < B->GetEng()) return -1;
	return 0;
}

int compareHist(Student* A, Student* B)
{
	if (A->GetHist() > B->GetHist()) return 1;
	if (A->GetHist() < B->GetHist()) return -1;
	return 0;
}

int compareAvg(Student* A, Student* B)
{
	if (A->GetAvg() > B->GetAvg()) return 1;
	if (A->GetAvg() < B->GetAvg()) return -1;
	return 0;
}
