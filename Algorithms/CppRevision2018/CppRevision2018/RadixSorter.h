#pragma once
#include <vector>
#include "ArraySorter.h"
#include "HelperFunctions.cpp"

template <typename T>
class RadixSorter : public ArraySorter<T>
{
public:
	RadixSorter();
	RadixSorter(std::vector<T> v);

	virtual ~RadixSorter();

protected:
	int sort() override;

private:
	// A utility function to get maximum value in arr[]
	int getMax();
	void countSort(int exp);
};
