#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#pragma warning(disable : 4996)


int lcm(const int a, const int b);
int gcd(const int a, const int b);

int main()
{
	double a, aD, b, bD;

	while (scanf("%lf/%lf + %lf/%lf", &a, &aD, &b, &bD) == 4)
	{
		const double result = a / aD + b / bD;

		//result is an int
		if (result == static_cast<int>(result))
		{
			cout << result << "\n";
			continue;
		}

		//different divisors
		if (aD != bD)
		{
			const int divisor = lcm(aD, bD);
			const int numerator = a * (divisor / aD) + b * (divisor / bD);
			const int cd = gcd(numerator, divisor);

			cout << numerator / cd << "/" << divisor / cd << "\n";
			continue;
		}

		//equal divisors, but the result is a fraction
		const int cd = gcd(a + b, aD);
		cout << (a + b) / cd << "/" << aD / cd << "\n";
	}

	system("pause");
	return 0;
}

///finds the least common multiple of two numbers
int lcm(const int a, const int b)
{
	return abs(a * b) / gcd(a, b);
}

///finds the greates common divisor of two numbers
int gcd(const int a, const int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}
