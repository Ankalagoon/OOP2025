#pragma once
#include <exception>
#include <iostream>

using namespace std;
/*
template array minimal:
operator adunare (concatenare), scadare, 
inmultire cu un scalar, impartire cu un scalar, 
indexare,cautare elemente
, array in array,

metode de manipulare elemente, insert,delete

sortare, la fiind / sortare permitem si callbacks, iterator!!
*/

class Div0 : public exception
{
	virtual const char* what() const throw()
	{
		return "Ai impartit la 0";
	}
};

class IndOut : public exception
{
	virtual const char* what() const throw()
	{
		return "Index out of array";
	}
};

class ArrEmpty : public exception
{
	virtual const char* what() const throw()
	{
		return "Array-ul este gol";
	}
};
class TooBig : public exception
{
	virtual const char* what() const throw()
	{
		return "Marimea este mai mare decat array-ul dat";
	}
};



template<typename T>
class Iterator {
public:
	int index;
	T* vect;
	Iterator(int index, T* v) {
		this->index = index;
		this->vect = v;
	}
	Iterator<T> operator++();
	bool operator!=(Iterator<T> other);
	T operator*();
};

template<typename T>
class MinArray {
	int size;
	T* v;
public:
	MinArray();
	MinArray(T x);
	MinArray(int n,T* a);
	MinArray(MinArray<T>& a);
	MinArray(MinArray<T>&& a);
	~MinArray();
	MinArray<T> operator-(MinArray<T> other);
	MinArray<T> operator+(const MinArray<T>& other);
	MinArray<T> operator=(const MinArray<T>& other);

	Iterator<T> begin() {
		Iterator<T> x(0, v);
		return x;
	}
	Iterator<T> end() {
		Iterator<T> x(size, v);
		return x;
	}
	void operator*(T x);
	void operator/(T x);
	
	T& operator[](int x);
	bool Incl(MinArray<T> other);
	int Find(T x);
	void Sort(bool(*Comp)(T,T));
	void swap(int a, int b);
	void Insert(T x);
	void Insert(int p, T x);
	void Delete(int p);
	void Add(int p,T x);
	void Sub(int p,T x);
	bool Empty();
};

template<typename T>
inline MinArray<T>::MinArray() 
{
	this->v = new T[1000];
	this->size = 0;
}

template<typename T>
inline MinArray<T>::MinArray(T x)
{
	v = new T[1000];
	v[0] = x;
	this->size = 0;
}

template<typename T>
inline MinArray<T>::MinArray(int n,T* a)
{
	this->v = new T[1000];
	this->size = 0;
	try {
		if (a[n - 1] == NULL) throw TooBig();
		this->size = n;
		this->v = a;
	}
	catch (exception& e)
	{
		cout << e.what() << '\n';
	}
}
template<typename T>
inline MinArray<T>::MinArray(MinArray<T>& other)
{
	this->v = new T[1000];
	this->size = other.size;
	for (int i = 0;i < other.size;i++) {
		this->v[i] = other.v[i];
	}
}
template<typename T>
inline MinArray<T>::MinArray(MinArray<T>&& other)
{
	this->v = new T[1000];
	this->size = other.size;
	for (int i = 0;i < other.size;i++) {
		this->v[i] = other.v[i];
	}
	other.v = nullptr;
	other.size = 0;
}

template<typename T>
inline MinArray<T>::~MinArray()
{
	this->v = nullptr;
	this->size = 0;
}

template<typename T>
inline MinArray<T> MinArray<T>::operator+(const MinArray<T>& other){
	MinArray<T> x;
	for (int i = 0; i < this->size;i++) {
		x.v[i] = this->v[i];
	}
	for (int i = this->size; i < this->size + other.size;i++) {
		x.v[i] = other.v[i - this->size];
	}
	x.size += other.size+this->size;
	return x;
}

template<typename T>
inline MinArray<T> MinArray<T>::operator=(const MinArray<T>& other)
{
	this->v = new T;
	this->v = other.v;
	this->size = other.size;
	return *this;
}

template<typename T>
inline MinArray<T> MinArray<T>::operator-(MinArray<T> other)
{
	MinArray<T> ar(this->size, this->v);
	int p;
	T x;
	for (int i = 0;i < other.size;i++) {
		if (p = ar.Find(other.v[i])) {
			ar.v[p] = ar.v[this->size - 1];
			ar.size--;
		}
	}
	return ar;
}

template<typename T>
inline void MinArray<T>::operator*(T x)
{
	for (int i = 0;i < this->size;i++) {
		this->v[i] *= x;
	}
}

template<typename T>
inline void MinArray<T>::operator/(T x)
{
	try {
		if (x == 0) throw Div0();
		for (int i = 0;i < this->size;i++) {
			this->v[i] /= x;
		}
	}
	catch (exception& e)
	{
		cout << e.what() << '\n';
	}
}

template<typename T>
inline T& MinArray<T>::operator[](int x)
{
	try {
		if (x >= this->size) throw IndOut();
		return this->v[x];
	}
	catch (exception& e)
	{
		cout << e.what() << '\n';
	}
}

template<typename T>
inline bool MinArray<T>::Incl(MinArray<T> other)
{
	try {
		if (other.Empty()) throw ArrEmpty();
		for (int i = 0;i < other.size;i++) {
			if (!this->Find(other[v[i]])) return false;
		}
		return true;
	}
	catch (exception& e)
	{
		cout << e.what() << '\n';
	}
	return false;
}

template<typename T>
inline int MinArray<T>::Find(T x)
{
	for (int i = 0;i < this->size;i++) {
		if (this->v[i] == x) return i;
	}
	return -1;
}

template<typename T>
inline void MinArray<T>::Sort(bool(*Comp)(T, T))
{
	for (int i = 0;i < this->size;i++) {
		for (int j = 0;j < this->size;j++) {
			if (Comp(this->v[i], this->v[j])) this->swap(i, j);
		}
	}
}

template<typename T>
inline void MinArray<T>::swap(int a, int b)
{
	try {
		if (a > this->size || b > this->size) throw IndOut();
		T x;
		x = this->v[a];
		this->v[a] = this->v[b];
		this->v[b] = x;
	}
	catch (exception& e)
	{
		cout << e.what() << '\n';
	}
}

template<typename T>
inline void MinArray<T>::Insert(T x)
{
	this->v[this->size] = x;
	this->size++;
}

template<typename T>
inline void MinArray<T>::Insert(int p, T x)
{
	for (int i = this->size;i > p;i--) {
		this->v[i] = this->v[i - 1];
	}
	this->v[p] = x;
	this->size++;
}

template<typename T>
inline void MinArray<T>::Delete(int p)
{
	for (int i = p ;i < this->size-1;i++) {
		this->v[i] = this->v[i + 1];
	}
	this->size--;
}

template<typename T>
inline void MinArray<T>::Add(int p,T x)
{
	this->v[p] += x;
}

template<typename T>
inline void MinArray<T>::Sub(int p, T x)
{
	this->v[p] -= x;
}

template<typename T>
inline bool MinArray<T>::Empty()
{
	return this->size == 0;
}

template<typename T>
inline Iterator<T> Iterator<T>::operator++()
{
	this->index++;
	return *this;
}

template<typename T>
inline bool Iterator<T>::operator!=(Iterator<T> other)
{
	return this->index != other.index;
}

template<typename T>
inline T Iterator<T>::operator*()
{
	return this->vect[this->index];
}
