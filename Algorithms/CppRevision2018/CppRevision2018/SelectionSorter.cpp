#include "SelectionSorter.h"
#include "HelperFunctions.cpp"
#include <ctime>


template <typename T>
SelectionSorter<T>::SelectionSorter()
{
}

template <typename T>
SelectionSorter<T>::SelectionSorter(std::vector<T> v) : ArraySorter<T>(v)
{
	clock_t beginT = clock();

	this->SelectionSorter<T>::sort();

	clock_t endT = clock();
	this->seconds_elapsed = double(endT - beginT) / CLOCKS_PER_SEC;
}

template <typename T>
SelectionSorter<T>::~SelectionSorter()
{
}

template <typename T>
int SelectionSorter<T>::sort()
{
	for (int i = 0; i < this->v.size() - 1; ++i)
	{
		int minPos = i;

		//find position of smallest int
		for (int j = i + 1; j < this->v.size(); ++j)
		{
			if (this->v[minPos] > this->v[j])
			{
				minPos = j;
			}
		}

		swapValues(this->v[i], this->v[minPos]);
	}
	return 0;
}

template SelectionSorter<int>;
