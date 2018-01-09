#include "RadixSorter.h"
#include <queue>
#include <ctime>
#include <vector>

template <typename T>
RadixSorter<T>::RadixSorter()
{
}

template <typename T>
RadixSorter<T>::RadixSorter(std::vector<T> v) : ArraySorter<T>(v)
{
	clock_t beginT = clock();

	this->RadixSorter<T>::sort();

	clock_t endT = clock();
	this->seconds_elapsed = double(endT - beginT) / CLOCKS_PER_SEC;
}

template <typename T>
RadixSorter<T>::~RadixSorter()
{
}

template <typename T>
int RadixSorter<T>::sort()
{
	// Find the maximum number to know number of digits
	int m = getMax();

	// Do counting sort for every digit. Note that instead
	// of passing digit number, exp is passed. exp is 10^i
	// where i is current digit number
	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(exp);

	return 0;
}

template <typename T>
int RadixSorter<T>::getMax()
{
	int mx = this->v[0];
	for (int i = 1; i < this->v.size(); i++)
		if (this->v[i] > mx)
			mx = this->v[i];
	return mx;
}

template <typename T>
void RadixSorter<T>::countSort(int exp)
{
	int n = this->v.size();
	std::vector<int> output(n); // output array
	int i, buckets[10] = {0};

	// Store count of occurrences in count[]
	for (i = 0; i < n; i++)
	{
		int pos = (this->v[i] / exp) % 10;
		++buckets[pos];
	}

	// Change count[i] so that count[i] now contains actual
	//  position of this digit in output[]
	for (i = 1; i < 10; i++)
		buckets[i] += buckets[i - 1]; //TODO: understand why this works

	// Build the output array
	for (i = n - 1; i >= 0; i--)
	{
		int digit = (this->v[i] / exp) % 10;
		output[buckets[digit] - 1] = this->v[i];
		--buckets[digit];
	}

	// Copy the output array to original vector, so that original vector now
	// contains sorted numbers according to current digit
	for (i = 0; i < n; i++)
		this->v[i] = output[i];
}

template RadixSorter<int>;
