#pragma once
#include "pch.h"
template <class T>
class SortClass
{
public:
    void Sort(T* s, bool desc = 0)
    {
        int n = 0, i;
        bool ok;
        for (n = 0; s[n] != NULL; n++)///1
            ;
        ok = 1;
        n--;//2
        while (ok)
        {
            ok = 0;
            for (i = 1; i < n; i++)
                if ((s[i] > s[i + 1]) ^ desc)///3 ///4
            {
                T aux = s[i];
                s[i] = s[i + 1];
                s[i + 1] = aux;
                ok = 1;
            }
        }
    }
};