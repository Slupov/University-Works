#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

bool* sieve;

bool isPrime(int i);
void calculateSieve();

int main()
{
	sieve = new bool[1000];
	calculateSieve();

	unsigned short s;
	unsigned int N;

	while (cin >> s >> N)
	{
//		clock_t begin = clock();

		srand(s);

		int primes = 0;

		for (int i = 0; i < N; ++i)
		{
			//iterating algorithm
//			if (isPrime(rand() % 1000))
//			{
//				primes++;
//			}

			//sieve of erathostenes algorithm
			if (sieve[rand() % 1000])
			{
				primes++;
			}
		}

		std::cout << primes << endl;

//		clock_t end = clock();
//		cout << "time: " << double(end - begin) / CLOCKS_PER_SEC << endl;
	}


	delete[] sieve;
	return 0;
}

bool isPrime(const int num)
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

void calculateSieve()
{
	for (int i = 0; i < 1000; ++i)
	{
		sieve[i] = true;
	}

	sieve[0] = sieve[1] = false;

	for (int p = 2; p < 1000; p++)
	{
		for (int j = 2*p; j < 1000; j+= p)
		{
			sieve[j] = false;
		}
	}

//	for (int i = 0; i < 1000; ++i)
//	{
//		if (sieve[i])
//		{
//			cout << i << endl;
//		}
//	}
}
