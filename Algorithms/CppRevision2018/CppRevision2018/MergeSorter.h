#pragma once
#include "ArraySorter.h"
#include <vector>

template <typename T>
class MergeSorter : public ArraySorter<T>
{
public:
	MergeSorter();
	MergeSorter(std::vector<T> v);

	virtual ~MergeSorter();

protected:
	int sort() override;

private:
	int merge_sort_start(std::vector<int>& v);
	int merge(std::vector<int>& left, std::vector<int>& right, std::vector<int>& v);
};
