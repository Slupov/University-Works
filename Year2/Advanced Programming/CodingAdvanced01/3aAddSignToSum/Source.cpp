//all solutions included
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

bool checkSol(vector<int>& numbers, int sum);
void variate(int i, vector<int>& numbers, int sum);

//todo: add empty row if no solution for ROW found
//todo: print only a single solution per ROW

int main()
{
	bool reading = true;
	string line = "";

	//input
	while (getline(cin, line))
	{
		//line input
		vector<int> numbers;
		istringstream iss(line);

		int num;
		while (iss >> num)
		{
			numbers.push_back(num);
		}
		//end of line input

		const int sum = numbers[numbers.size() - 1];
		numbers.pop_back();

		variate(0, numbers, sum);
	}
}

void variate(const int i, vector<int>& numbers, const int sum)
{
	if (i >= numbers.size())
	{
		checkSol(numbers, sum);
		return;
	}

	numbers[i] = abs(numbers[i]);
	variate(i + 1, numbers, sum);

	numbers[i] = -abs(numbers[i]);
	variate(i + 1, numbers, sum);
}


bool checkSol(vector<int>& numbers, const int sum)
{
	int tempSum = 0;
	for (int i = 0; i < numbers.size(); i++) tempSum += numbers[i];

	if (tempSum == sum)
	{
		/* solution found */
		for (int i = 0; i < numbers.size(); i++)
		{
			if (numbers[i] > 0) //positive number
			{
				if (i != 0) printf("+%d", numbers[i]);
				else printf("%d", numbers[i]);
			}
			else printf("%d", numbers[i]);
		}

		printf("=%d\n", tempSum);

		return true;
	}

	return false;
}
