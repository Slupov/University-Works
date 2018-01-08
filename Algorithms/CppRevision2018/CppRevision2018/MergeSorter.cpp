#include "MergeSorter.h"
#include <ctime>
#include <iostream>

template <typename T>
MergeSorter<T>::MergeSorter()
{
}

template <typename T>
MergeSorter<T>::MergeSorter(std::vector<T> v) : ArraySorter<T>(v)
{

}

template <typename T>
MergeSorter<T>::~MergeSorter()
{
}

template <typename T>
int MergeSorter<T>::sort()
{
	clock_t beginT = clock();

	merge_sort_start(this->v);

	clock_t endT = clock();

	this->print();
	std::cout << "merge sort time: " << double(endT - beginT) / CLOCKS_PER_SEC << endl;

	return 0;
}

template <typename T>
int MergeSorter<T>::merge_sort_start(std::vector<int>& v)
{
	int n = v.size();

	if (n < 2) return 0;

	int mid = n / 2;

	std::vector<int> left(mid);
	for (int i = 0; i < mid; ++i)
	{
		left[i] = v[i];
	}

	std::vector<int> right(n - mid);
	for (int i = mid; i < n; ++i)
	{
		right[i - mid] = v[i];
	}

	merge_sort_start(left);
	merge_sort_start(right);

	merge(left, right, v);

	//	print(v);
	return 0;
}

template <typename T>
int MergeSorter<T>::merge(std::vector<int>& left, std::vector<int>& right, std::vector<int>& v)
{
	int nL = left.size();
	int nR = right.size();

	int li = 0, ri = 0, i = 0;

	while (li < nL && ri < nR)
	{
		if (left[li] <= right[ri])
		{
			v[i] = left[li];
			li++;
		}
		else
		{
			v[i] = right[ri];
			ri++;
		}

		i++;
	}

	//if some of the two arrays got all used first
	//fill up all remaining with leftovers of other array
	while (li < nL)
	{
		v[i] = left[li];
		li++;
		i++;
	}

	while (ri < nR)
	{
		v[i] = right[ri];
		ri++;
		i++;
	}

	return 0;
}
