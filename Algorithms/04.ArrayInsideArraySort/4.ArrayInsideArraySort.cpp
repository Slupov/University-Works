#include<iostream>
using namespace std;

//sorting array inside another array
int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	int* arr2 = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int max = arr[0];

	for (int i = 1; i < n; i++)
	{
		//update max
		if (max < arr[i])
		{
			max = arr[i];
		}
	}

	//make current max last in arr2
	arr2[n - 1] = max;

	int min;
	int minPos;

	for (int i = 0; i < n - 1; i++)
	{
		min = arr[0];
		minPos = 0;

		//find min (prev min got "destroyed")
		for (int j = 1; j < n; j++)
		{
			if (min > arr[j])
			{
				//update min
				min = arr[j];
				minPos = j;
			}
		}

		arr2[i] = min;
		//"destroying" the min element in original array
		arr[minPos] = max;
	}

	for (int i = 0; i < n; i++)
	{
		cout << arr2[i] << " ";
	}
	return 0;
}
