#pragma once
#include<iostream>
#include <utility>

template <typename K, typename V>
struct trip {
	K key;
	V value;
	int index;
};
template <typename K,typename V>
struct vrajeala {
	K first;
	V second;
};
template <typename K, typename V>
class Iterator {
	public:
	int index;
	vrajeala<K, V> *vraj;
	Iterator(int index, vrajeala<K,V> *vraj) {
		this->index = index;
		this->vraj = vraj;
	}
	Iterator<K, V> operator++();
	bool operator!=(Iterator<K, V> x);
	trip<K,V> operator*();
};



template <typename K,typename V>
class Map
{
	vrajeala<K, V>* v;
	int size;
public:
	Map();
	void Set(const K& key, V& value);
	bool Get(const K& key, V& value);
	int Count();
	void Clear();
	bool Delete(const K& key);
	Iterator<K,V> begin() {
		Iterator<K,V> x(0, v);
		return x;
	}
	Iterator<K,V> end() {
		Iterator<K,V> x(size, v);
		return x;
	}
	V& operator[](const K& key);
};

template<typename K, typename V>
inline Map<K, V>::Map()
{
	this->size = 0;
	this->v = new vrajeala<K, V>;
}

template<typename K, typename V>
inline void Map<K, V>::Set(const K& key, V& value)
{
	this->v[size].first = key;
	this->v[size].second = value;
	this->size++;
}

template<typename K, typename V>
inline bool Map<K, V>::Get(const K& key, V& value)
{
	for (int i = 0;i < this->size;i++) {
		if (key == this->v[i].first) {
			value = this->v[i].second;
			return true;
		}
	}
	return false;
}

template<typename K, typename V>
inline int Map<K, V>::Count()
{
	return this->size;
}

template<typename K, typename V>
inline void Map<K, V>::Clear()
{
	delete this->v;
	this->v = new vrajeala<K, V>;
}

template<typename K, typename V>
inline bool Map<K, V>::Delete(const K& key)
{
	for (int i = 0;i < this->size;i++) {
		if (key == this->v[i].first) {
			if (i != this->size - 1) 
				this->v[i] = this->v[this->size - 1];
			this->size--;
			return true;
		}
	}
	return false;
}


template<typename K, typename V>
inline V& Map<K, V>::operator[](const K& key)
{
	for (int i = 0;i < this->size;i++) {
		if (key == this->v[i].first) {
		
			return this->v[i].second;
		}
	}
	this->v[size].first = key;
	this->v[size].second = V();
	this->size++;
	return this->v[size-1].second;
}

template<typename K, typename V>
inline Iterator<K, V> Iterator<K, V>::operator++()
{
	this->index++;
	return *this;
}

template<typename K, typename V>
inline bool Iterator<K, V>::operator!=(Iterator<K, V> x)
{
	return x.index != this->index;
}

template<typename K, typename V>
inline trip<K,V> Iterator<K, V>::operator*()
{
	trip<K,V> a;
	a.index = this->index;
	a.key = this->vraj[index].first;
	a.value = this->vraj[index].second;
	return a;
}
