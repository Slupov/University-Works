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
	this->v = std::vector<int>{ 3221, 1, 10, 9680, 577, 9420, 7, 5622, 4793, 2030, 3138, 82, 2599, 743, 4127 };
	int n = this->v.size();
	std::vector<int> output(n); // output array
	int buckets[10] = {0};

	// Store count of occurrences in buckets[]
	for (int i = 0; i < n; i++)
	{
		int pos = (this->v[i] / exp) % 10;
		++buckets[pos];
	}

	// Change buckets[i] so that buckets[i] now contains actual
	//  position (in output[]) of the numbers that were in this digit-indexed bucket
	for (int i = 1; i < 10; i++)
		buckets[i] += buckets[i - 1]; 

	// Build the output array
	for (int i = n - 1; i >= 0; i--)
	{
		//get current exponent's digit from the number
		int digit = (this->v[i] / exp) % 10;

		const int outputPos = buckets[digit] - 1;
		output[outputPos] = this->v[i];
		--buckets[digit];
	}

	// Copy the output array to original vector, so that original vector now
	// contains sorted numbers according to current digit
	for (int i = 0; i < n; i++)
		this->v[i] = output[i];
}

template RadixSorter<int>;
