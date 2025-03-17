#include "Sort.h"
#include <iostream>
#include <random>
#include <time.h>
#include <cstdarg>

using namespace std;

Sort::Sort(int num, int mik, int mak)
{
	this->n = num;
	time_t t;
	srand((unsigned)time(&t));
	for(int i=0;i<this->n;i++)
		this->list[i]=mik + (rand()%(mak-mik+1));
}

Sort::Sort(int num, int* a[])
{
	this->n=num;
	for (int i = 0;i < num;i++) {
		this->list[i] = *a[i];
	}
}

Sort::Sort(int num, ...)
{
	this->n = num;
	va_list vl;
	va_start(vl, num);
	for(int i=0;i<num;i++)
		this->list[i] = va_arg(vl, int);
	va_end(vl);

}

Sort::Sort(int num,const char* s)
{
	this->n = num;
	int x = 0,p=0;
	int val;
	while (x < num) {
		val = 0;
		while (s[p] != ',' && s[p] != '\0') {
			val *= 10;
			val += s[p] - '0';
			p++;
		}
		p++;
		this->list[x] = val;
		x++;
	}
}

void Sort::InsertSort(bool ascendent)
{
	int x;
	for (int i = 0;i < this->n;i++) {
		for (int j = i - 1;j >= 0;j--) {
			if ((this->list[j] > this->list[j + 1]) ^ ascendent) {
				x = this->list[j];
				this->list[j] = this->list[j + 1];
				this->list[j + 1] = x;
			}
		}
	}
}

void Sort::QuickSort(bool ascendent)
{
	int sts[1005],std[1005], top = 0,x;
	top++;
	sts[top] = 0;
	std[top] = this->n - 1;
	int st, dr;
	while (top > 0) {
		st = sts[top];
		dr = std[top];
		top--;
		if (st < dr) {
			int poz = st, i = st;
			while (i <= dr) {
				if (this->list[i] == this->list[dr]);
				else if ((this->list[i] < this->list[dr]) ^ ascendent) {
					x = this->list[i];
					this->list[i] = this->list[poz];
					this->list[poz] = x;
					poz++;
				}
				i++;
			}
		
				x = this->list[dr];
				this->list[dr] = this->list[poz];
				this->list[poz] = x;
			
			top++;
			sts[top] = st;
			std[top] = poz-1;
			top++;
			sts[top] = poz+1;
			std[top] = dr;
		}
	}


}

void Sort::BubbleSort(bool ascendent)
{
	int ok = 1,x;
	while (ok) {
		ok = 0;
		for (int i = 0;i < this->n-1;i++) {
			if (this->list[i] == this->list[i + 1]) continue;
			else if ((this->list[i] > this->list[i + 1]) ^ ascendent) {
				x = this->list[i];
				this->list[i] = this->list[i+1];
				this->list[i+1] = x;
				ok = 1;
			}
		}
	}
}

void Sort::Print()
{
	for (int i = 0;i < this->n;i++) {
		printf("%d ",this->list[i]);
	}
	printf("\n");
}

int Sort::GetElementsCount()
{
	return this->n;
}
int Sort::GetElementFromIndex(int index)
{
	return this->list[index];
}
;
