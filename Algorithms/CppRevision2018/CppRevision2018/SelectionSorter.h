#pragma once
#include "ArraySorter.h"

template <typename T>
class SelectionSorter : public ArraySorter<T>
{
public:
	SelectionSorter();
	SelectionSorter(std::vector<T> v);

	virtual ~SelectionSorter();

protected:
	int sort() override;
};
