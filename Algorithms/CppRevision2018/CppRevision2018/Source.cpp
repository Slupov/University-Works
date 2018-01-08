#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
#include "MergeSorter.h"

#define LOWER_N 10
#define UPPER_N 20

using namespace std;

int bubble_sort(vector<int> v);
int selection_sort(vector<int> v);
int insertion_sort(vector<int> v);

int merge_sort(vector<int> v);
int merge_sort_start(vector<int>& v);
int merge(vector<int>& left, vector<int>& right, vector<int>& v);

void print(const vector<int>& v);
int next_random(const int lower, const int upper);

template <typename T>
void swapValues(T& a, T& b);

int main()
{
	srand(time(NULL));
	int n = next_random(LOWER_N, UPPER_N);

	//input random vector
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		v[i] = next_random(1, 100);
	}

//	cout << "original" << endl;
//	print(v);
//	cout << "^^^^^^^^^^^^^^^^" << endl;
//
//	bubble_sort(v);
//	cout << "----------------" << endl;
//	selection_sort(v);
//	cout << "----------------" << endl;
//	insertion_sort(v);
//	cout << "----------------" << endl;
//	merge_sort(v);

	MergeSorter<int>* sorter = new MergeSorter<int>(v);
//	sorter->print();

	return 0;
}

int next_random(const int lower, const int upper)
{
	return lower + rand() % (upper - lower + 1);
}

int bubble_sort(vector<int> v)
{
	clock_t beginT = clock();

	bool swapped = true;
	int end = v.size() - 1;

	do
	{
		swapped = false;

		for (int i = 0; i < end; ++i)
		{
			if (v[i] > v[i + 1])
			{
				swapValues(v[i], v[i + 1]);
				swapped = true;
			}
		}

		end--;
	}
	while (swapped);

	clock_t endT = clock();
	print(v);
	cout << "bubble sort time: " << double(endT - beginT) / CLOCKS_PER_SEC << endl;

	return 0;
}

int selection_sort(vector<int> v)
{
	clock_t beginT = clock();

	for (int i = 0; i < v.size() - 1; ++i)
	{
		int minPos = i;

		for (int j = i + 1; j < v.size(); ++j)
		{
			if (v[minPos] > v[j])
			{
				minPos = j;
			}
		}

		swapValues(v[i], v[minPos]);
	}

	clock_t endT = clock();

	print(v);
	cout << "selection sort time: " << double(endT - beginT) / CLOCKS_PER_SEC << endl;

	return 0;
}

int insertion_sort(vector<int> v)
{
	clock_t beginT = clock();
	for (int i = 1; i < v.size(); ++i)
	{
		int picked = v[i];

		for (int j = i - 1; j >= 0; --j)
		{
			if (v[j] <= picked)
			{
				break;
			}

			v[j + 1] = v[j];
			v[j] = picked;
		}
	}

	clock_t endT = clock();

	print(v);
	cout << "insertion sort time: " << double(endT - beginT) / CLOCKS_PER_SEC << endl;

	return 0;
}

int merge_sort(vector<int> v)
{
	clock_t beginT = clock();

	merge_sort_start(v);

	clock_t endT = clock();

	print(v);
	cout << "merge sort time: " << double(endT - beginT) / CLOCKS_PER_SEC << endl;

	return 0;
}

int merge_sort_start(vector<int>& v)
{
	int n = v.size();

	if (n < 2) return 0;

	int mid = n / 2;

	vector<int> left(mid);
	for (int i = 0; i < mid; ++i)
	{
		left[i] = v[i];
	}

	vector<int> right(n - mid);
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

int merge(vector<int>& left, vector<int>& right, vector<int>& v)
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

template <typename T>
void swapValues(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

void print(const vector<int>& v)
{
	for (int num : v)
	{
		cout << setw(3) << right << num << " ";
	}

	cout << endl;
}
