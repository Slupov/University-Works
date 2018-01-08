#include "ArraySorter.h"
#include <iostream>
#include <iomanip>

template <typename T>
ArraySorter<T>::ArraySorter()
{
	this.v = std::vector<T>();
}

template <typename T>
ArraySorter<T>::ArraySorter(std::vector<T> v)
{
	this.v = v;
}

template <typename T>
ArraySorter<T>::~ArraySorter()
{
}

template <typename T>
void ArraySorter<T>::print()
{
	for (T num : v)
	{
		std::cout << std::setw(3) << std::right << num << " ";
	}

	std::cout << std::endl;
}
