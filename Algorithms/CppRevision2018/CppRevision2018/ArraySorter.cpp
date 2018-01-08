#include "ArraySorter.h"
#include "HelperFunctions.cpp"
#include <iostream>
#include <iomanip>

template <typename T>
ArraySorter<T>::ArraySorter(): seconds_elapsed(0)
{
	this->v = std::vector<T>();
}

template <typename T>
ArraySorter<T>::ArraySorter(std::vector<T> v): seconds_elapsed(0)
{
	this->v = v;
}

template <typename T>
ArraySorter<T>::~ArraySorter()
{
}

template <typename T>
void ArraySorter<T>::print()
{
//	printVector(this->v);
}

template <typename T>
double ArraySorter<T>::sorting_time()
{
	return this->seconds_elapsed;
}
