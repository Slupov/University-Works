#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

long double a;
#define FN 82264

long double func(long double x)
{
	return x * x * x * x * x - a * (x * x) - FN % 100;
}

void bisec(long double& a)
{
	long double c;
	long double precision = .00000000000000000001;
	long double a1 = 0;
	long double b1 = 10;
	bool isFound = false;
	int count = 0;

	c = a1;
	while (count < 100)
	{
		if ((b1 - a1) > precision)
		{
			c = (a1 + b1) / 2.0;
			if (func(c) == 0.0)
			{
				break;
			}
			else if (func(c) * func(a1) < 0)
			{
				b1 = c;
			}
			else
			{
				a1 = c;
			}
		}
		else break;
		count++;
	}
	cout << setprecision(19) << fixed << c << endl;
}

int main()
{
	while (cin >> a)
	{
		bisec(a);
	}
	return 0;
}
