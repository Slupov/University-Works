#pragma once
#include "ArraySorter.h"

template<typename T>
class InsertionSorter : public ArraySorter<T>
{
public:
	InsertionSorter();
	InsertionSorter(std::vector<T> v);

	virtual ~InsertionSorter();

protected:
	int sort() override;
};