#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

//bidirectional selection sort

void rand_seed()
{
	int seed = static_cast<int>(time(0));
	srand(seed);
}

int rand_int(int a, int b)
{
	return a + rand() % (b - a + 1);
}

inline void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void bidirectionalSelectionSort(vector<int>& a)
{
	int k = a.size();

	for (int i = 0; i < a.size(); ++i)
	{
		--k;
		int min = i;
		int max = k;

		if (k - i <= 0) break;

		//finding min and max positions
		for (int j = i; j <= k; ++j)
		{
			if (a[min] > a[j]) min = j;
			if (a[max] < a[j]) max = j;
		}

		if (i != min)
		{
			swap(a[i], a[min]);
			if (i == max)
			{
				//because it got swapped for min
				max = min;
			}
			min = i;
		}

		if (k != max)
		{
			swap(a[k], a[max]);
		}
	}
}

int main()
{
	rand_seed();
	vector<int> a(10);
	for (int i = 0; i < a.size(); ++i)
	{
		a[i] = rand_int(0, 100);
	}

	bidirectionalSelectionSort(a);

	for (int i = 0; i < a.size(); ++i)
	{
		cout << a[i] << " ";
	}

	return 0;
}
