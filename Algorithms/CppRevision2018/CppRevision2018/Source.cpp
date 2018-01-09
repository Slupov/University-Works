#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>

#include "HelperFunctions.cpp"
#include "MergeSorter.h"
#include "BubbleSorter.h"
#include "SelectionSorter.h"
#include "InsertionSorter.h"
#include "RadixSorter.h"

#define LOWER_N 10
#define UPPER_N 20

using namespace std;

int next_random(const int lower, const int upper);

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

	cout << "original" << endl;
	printVector(v);
	cout << "^^^^^^^^^^^^^^^^" << endl;

//	ArraySorter<int>* sorter = new BubbleSorter<int>(v);
//	cout << "Bubble sort time: " << sorter->sorting_time() << endl;
//	sorter->print();
//
//	sorter = new SelectionSorter<int>(v);
//	cout << "Selection sort time: " << sorter->sorting_time() << endl;
//	sorter->print();
//
//	sorter = new InsertionSorter<int>(v);
//	cout << "Insertion sort time: " << sorter->sorting_time() << endl;
//	sorter->print();
//
//	sorter = new MergeSorter<int>(v);
//	cout << "Merge sort time: " << sorter->sorting_time() << endl;
//	sorter->print();

	ArraySorter<int>* sorter = new RadixSorter<int>(v);
	cout << "Radix sort time: " << sorter->sorting_time() << endl;
	sorter->print();

 	return 0;
}

int next_random(const int lower, const int upper)
{
	return lower + rand() % (upper - lower + 1);
}
