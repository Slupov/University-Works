#include <iostream>
using namespace std;

#define FACULTY_NUMBER 82264

double func(double x, double a);
void bisection(double x1, double x2, double a);

double EPS = 1E-10;

int main()
{
	const double x1 = 0;
	const double x2 = 10;

	double a;
	while (cin >> a)
	{
		bisection(x1, x2, a);
	}

	return 0;
}

double func(double x, double a)
{
	return x * x * x * x * x - a * x * x - FACULTY_NUMBER % 100;
}

void bisection(double x1, double x2, double a)
{
	if (func(x1, a) * func(x2, a) >= 0)
	{
		cout << "NO SOLUTION";
		return;
	}

	double start = x1;

	//current section is bigger than the tolerance
	while ((x2 - x1) >= EPS)
	{
		//cut the section in half
		start = (x1 + x2) / 2;

		//solution found
		if (func(start, a) == 0.0)
			break;

		if (func(start, a) * func(x1, a) < 0)
			x2 = start;
		else
			x1 = start;
	}
	cout << start;
}
