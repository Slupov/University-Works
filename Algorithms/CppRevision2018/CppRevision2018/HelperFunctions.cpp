#pragma once
#include <iostream>
#include <vector>
#include <iomanip>

template <typename T>
void swapValues(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
void printVector(std::vector<T> v)
{
	for (T num : v)
	{
		std::cout << std::setw(3) << std::right << num << " ";
	}

	std::cout << std::endl;
}
