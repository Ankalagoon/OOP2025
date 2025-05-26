#pragma once

template<typename T>
class Surt {
private:
	T* v;
	int size;
public:
	Surt();
	Surt(int n,T a[]);
	Surt(Surt& o);
	Surt(Surt&& o);
	void push(T x);
	void set(int p, T x);
	void sort(bool(*Cmp)(T, T));
	T& operator[](int p);
	void SetSize(int n);
	int GetSize();
};

template<typename T>
inline Surt<T>::Surt()
{
	this->size = 0;
	this->v = new T[1005];
}

template<typename T>
inline Surt<T>::Surt(int n, T a[])
{
	this->size = n;
	this->v = new T[1005];
	for (int i = 0;i < n;i++) {
		this->v[i] = a[i];
	}
}

template<typename T>
inline Surt<T>::Surt(Surt& o)
{
	this->size = o.size;
	for (int i = 0;i < this->size;i++) {
		this->v[i] = o.v[i];
	}
}

template<typename T>
inline Surt<T>::Surt(Surt&& o)
{
	this->size = o.size;
	for (int i = 0;i < this->size;i++) {
		this->v[i] = o.v[i];
	}
	o.size = 0;
	delete o.v;
}

template<typename T>
inline void Surt<T>::push(T x)
{
	this->v[this->size] = x;
	this->size++;
}

template<typename T>
inline void Surt<T>::set(int p, T x)
{
	this->v[p] = x;
}

template<typename T>
inline void Surt<T>::sort(bool(*Cmp)(T, T))
{
	for (int i = 1;i < this->size;i++) {
		for (int j = 1;j < this->size;j++) {
			if (!Cmp(v[i], v[j])) {
				T x;	
				x = v[i];
				v[i] = v[j];
				v[j] = v[i];
			}
		}
	}
}

template<typename T>
inline T& Surt<T>::operator[](int p)
{
	return this->v[p];
}

template<typename T>
inline void Surt<T>::SetSize(int n)
{
	this->size = n-1;
}

template<typename T>
inline int Surt<T>::GetSize()
{
	return this->size + 1;
}
