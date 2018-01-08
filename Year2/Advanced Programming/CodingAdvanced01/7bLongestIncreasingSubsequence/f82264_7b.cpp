#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;

	while (cin >> n)
	{
		vector<int> seq;

		for (int i = 0; i < n; ++i)
		{
			int num;
			cin >> num;
			seq.push_back(num);
		}

		int previous_idx = 0;

		int max_length = 0;

		for (int st = 0; st < n; ++st)
		{
			if (seq[st] >= seq[previous_idx] && st != 0)
			{
				continue;
			}

			int currentLenght = 0;

			for (int i = st; i < n; ++i)
			{
				if (seq[i] >= seq[st])
				{
					seq[st] = seq[i];
					currentLenght++;
				}
			}

			if (currentLenght > max_length)
			{
				max_length = currentLenght;
			}

			previous_idx = st;
		}

		cout << max_length << endl;
	}

	return 0;
}
