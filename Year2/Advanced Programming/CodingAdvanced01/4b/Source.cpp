#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int L;
int N;
string input_text;

int getIndex();

int main()
{
	//input
	cin >> N >> L;
	cin.ignore();
	cin >> input_text;

	const int startIndex = getIndex();
	sort(input_text.begin() + startIndex, input_text.begin() + startIndex + L);

	cout << input_text << endl;
}

int getIndex()
{
	for (int i = 0; i < N - L + 1; i++)
	{
		const char startChar = input_text[i];

		for (int j = i + 1; j < i + L; j++)
		{
			if (input_text[j] < startChar)
				return i;
		}
	}
	return N - L;
}
