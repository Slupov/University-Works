#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

const int MAX_NOTES = 102;

int n_count;
int banknotes[MAX_NOTES];

bool compare(const int lhs, const int rhs)
{
	string num1 = std::to_string(lhs) + std::to_string(rhs);
	string num2 = std::to_string(rhs) + std::to_string(lhs);

	return strcmp(num1.c_str(), num2.c_str()) > 0;
}

void get_biggest_permutation()
{
	sort(banknotes, banknotes + n_count, compare);

	for (int i = 0; i < n_count; i++)
	{
		cout << banknotes[i];
	}
	cout << "\n";
}

int main()
{
	cin >> n_count;

	for (int i = 0; i < n_count; i++)
	{
		int note;
		cin >> note;
		banknotes[i] = note;
	}

	get_biggest_permutation();

	return 0;
}