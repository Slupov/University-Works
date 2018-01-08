#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
	string word;

	while (cin >> word)
	{
		unsigned int cycles = 0;
		string input;

		while (cin >> input)
		{
			if ((isdigit(input[0])))
			{
				cycles = atoi(input.c_str());
				cycles %= word.size();

				const string newWord = word.substr(cycles) + word.substr(0, cycles);
				cout << newWord << endl;
			}
			else word = input;
		}
	}
}
