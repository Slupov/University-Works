//F82264
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int toBaseTen(string& number, int base);

int main()
{
	int base;

	while (cin >> base)
	{
		string number;
		cin >> number;

		cout << toBaseTen(number, base) << endl;
	}

	return 0;
}

///converts from any base to base 10
int toBaseTen(string& number, int base)
{
	int result = 0;

	for (int i = 0; i < number.length(); ++i)
	{
		int currentDigit = number[i];

		if (currentDigit >= 65 && currentDigit <= 90) //ASCII upper case letter
		{
			//get the number equivalent of the letter
			currentDigit -= 55;
		}
		else if (currentDigit >= 48 && currentDigit <= 57) //ASCII digit
		{
			//get the number equivalent of the digit
			currentDigit -= 48;
		}

		int power = number.length() - 1 - i;

		if (power == 0)
		{
			result += currentDigit;
		}
		else
		{
			result += currentDigit * pow(base,power);
		}
	}

	return result;
}
