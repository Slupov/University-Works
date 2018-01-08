#pragma once
#include "ArraySorter.h"

template <typename T>
class BubbleSorter : public ArraySorter<T>
{
public:
	BubbleSorter();
	BubbleSorter(std::vector<T> v);

	virtual ~BubbleSorter();

protected:
	int sort() override;
};


