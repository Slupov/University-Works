#include <iostream>
#include <stdlib.h>
#include <limits.h>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

pair<int, int> BalancedPartition(vector<int> arr)
{
	int sum = 0;
	const int n = arr.size();

	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}

	int* s = new int[sum + 1];

	s[0] = 1;
	for (int i = 1; i < sum + 1; i++)
	{
		s[i] = 0;
	}

	int diff = INT_MAX;
	int ans = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = sum; j >= arr[i]; j--)
		{
			s[j] = s[j] | s[j - arr[i]];

			if (s[j] == 1)
			{
				if (diff > abs(sum / 2 - j))
				{
					diff = abs(sum / 2 - j);
					ans = j;
				}
			}
		}
	}

	diff = abs(sum - 2 * ans);
	int first = (sum - diff) / 2;
	int second = first + diff;

	delete[] s;
	return make_pair(first, second);
}

int main()
{
	string input;
	while (getline(cin, input))
	{
		stringstream ss(input);

		vector<int> arr;

		int num;
		while (ss >> num)
		{
			arr.push_back(num);
		}

		pair<int, int> result = BalancedPartition(arr);
		cout << result.first << " " << result.second << endl; // The difference between the sums of the two subsets
	}

	return 0;
}
