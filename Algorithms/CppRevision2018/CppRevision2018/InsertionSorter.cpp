#include "InsertionSorter.h"
#include <ctime>

template <typename T>
InsertionSorter<T>::InsertionSorter()
{
}

template <typename T>
InsertionSorter<T>::InsertionSorter(std::vector<T> v) : ArraySorter<T>(v)
{
	clock_t beginT = clock();

	this->InsertionSorter<T>::sort();

	clock_t endT = clock();
	this->seconds_elapsed = double(endT - beginT) / CLOCKS_PER_SEC;
}

template <typename T>
InsertionSorter<T>::~InsertionSorter()
{
}

template <typename T>
int InsertionSorter<T>::sort()
{
	for (int i = 1; i < this->v.size(); ++i)
	{
		int picked = this->v[i];

		for (int j = i - 1; j >= 0; --j)
		{
			if (this->v[j] <= picked)
			{
				break;
			}

			this->v[j + 1] = this->v[j];
			this->v[j] = picked;
		}
	}

	return 0;
}

template InsertionSorter<int>;