//F82264
#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int num);

int main()
{
	int B;

	while (cin >> B)
	{
		srand(B);
		int primesCount = 0;

		for (int i = 0; i < 10000; i++)
		{
			int num = rand() % 10000;
			if (isPrime(num))
			{
				primesCount++;
			}
		}

		std::cout << primesCount << std::endl;
	}

	return 0;
}

bool isPrime(int num)
{
	if (num < 2)
		return false;

	if (num == 2)
		return true;

	for (int i = 2; i <= sqrt(num); i++)
	{
		if (num % i == 0) return false;
	}

	return true;
}
