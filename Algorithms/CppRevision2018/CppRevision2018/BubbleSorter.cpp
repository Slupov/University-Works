#include "BubbleSorter.h"
#include "HelperFunctions.cpp"
#include <ctime>

template <typename T>
BubbleSorter<T>::BubbleSorter()
{
}

template <typename T>
BubbleSorter<T>::BubbleSorter(std::vector<T> v) : ArraySorter<T>(v)
{
	clock_t beginT = clock();

	this->BubbleSorter<T>::sort();

	clock_t endT = clock();
	this->seconds_elapsed = double(endT - beginT) / CLOCKS_PER_SEC;
}


template <typename T>
BubbleSorter<T>::~BubbleSorter()
{
}

template <typename T>
int BubbleSorter<T>::sort()
{
	bool swapped = true;
	int end = this->v.size() - 1;

	do
	{
		swapped = false;

		for (int i = 0; i < end; ++i)
		{
			if (this->v[i] > this->v[i + 1])
			{
				swapValues(this->v[i], this->v[i + 1]);
				swapped = true;
			}
		}

		end--;
	}
	while (swapped);

	return 0;
}

template BubbleSorter<int>;
