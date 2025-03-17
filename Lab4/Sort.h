#pragma once
class Sort
{
    int n;
    int list[1005];
public:
    //Constructors
    Sort(int num, int min, int max); ///random
    Sort(int num, int* a[]); /// vector
    Sort(int num, ...);
    Sort(int num, const char* s);   
    //Restul
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};

