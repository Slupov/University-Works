#pragma once
#include<vector>

template<typename T>
class ArraySorter
{
protected:
	std::vector<T> v;
	double seconds_elapsed;

	ArraySorter();
	ArraySorter(std::vector<T> v);

	~ArraySorter();

	virtual int sort() = 0;

public:
	virtual void print();
	virtual double sorting_time();
};

template ArraySorter<int>;