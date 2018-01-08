#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

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
void bubbleSort(vector<int>& arr) {
	bool swapped = true;
	int j = 0;
	int n = arr.size();

	//If at least one swap has been done, repeat
	while (swapped) {
		swapped = false;
		j++;
		for (int i = 0; i < n - j; i++) {
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
				swapped = true;
			}
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

	bubbleSort(a);

	for (int i = 0; i < a.size(); ++i)
	{
		cout << a[i] << " ";
	}
	return 0;
}