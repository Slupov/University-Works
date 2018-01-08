#pragma once
#include<vector>

template<typename T>
class ArraySorter
{
protected:
	std::vector<T> v;

	ArraySorter();
	ArraySorter(std::vector<T> v);

	~ArraySorter();

	virtual int sort() = 0;

public:
	virtual void print();
};


