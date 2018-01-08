#include <iostream>
#include <vector>
using namespace std;

/* Dynamic Programming C/C++ implementation of LIS problem */
int get_lis_length(vector<int> seq)
{
	int max = 0;
	int n = seq.size();
	vector<int> lis(n, 1);

	/* Compute optimized LIS values in bottom up manner */
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (seq[i] >= seq[j] && lis[i] <= lis[j] + 1)
			{
				lis[i] = lis[j] + 1;
			}
		}
	}

	/* Pick maximum of all LIS values */
	for (int i = 0; i < n; i++)
	{
		if (max < lis[i]) max = lis[i];
	}

	return max;
}

int main()
{
	int n;

	while (cin >> n)
	{
		vector<int> seq;

		//vector input
		for (int i = 0; i < n; ++i)
		{
			int num;
			cin >> num;
			seq.push_back(num);
		}

		cout << get_lis_length(seq) << endl;
	}

	return 0;
}
