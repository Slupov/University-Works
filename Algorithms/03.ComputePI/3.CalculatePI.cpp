#include<iomanip>
#include<fstream>
using namespace std;

double calculate_pi(int iterations, ofstream& of)
{
	double sum = 0.0;
	int sign = 1;

	for (int i = 0; i < iterations; i++)
	{
		sum += sign / (2.0 * i + 1.0);
		sign *= -1;

		if (i % 200 == 0)
		{
			of << left << setw(4) << "it: " << setw(5) << i;
			of << setw(5) << " pi: " << setprecision(15) << left << setw(15) << fixed << sum * 4 << endl;
		}
	}

	sum = sum * 4;
	of << "it: " << iterations << " pi: " << setprecision(15) << fixed << sum << endl;

	return sum;
}

int main()
{
	int iterations = 10000;
	ofstream of;
	of.open("output.txt");
	double pi = calculate_pi(10000, of);
	of.close();

	return 0;
}
