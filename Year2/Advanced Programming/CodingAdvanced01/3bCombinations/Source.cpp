//repetitive permutations
#include <iostream>
using namespace std;

unsigned long fac(const int num);
unsigned long fac(const int num, const int toNum);

int main()
{
	int boys = 0, girls = 0;
	cin >> boys >> girls;

	cout << fac(boys + girls, boys) / fac(girls) << endl;

	system("pause");
	return 0;
}

unsigned long fac(const int num)
{
	unsigned long factorial = 1;

	for (int i = num; i >= 1; i--)
	{
		factorial *= i;
	}

	return factorial;
}

//calculates partial factorial
//stops at toNum
unsigned long fac(const int num, const int toNum)
{
	unsigned long factorial = 1;

	for (int i = num; i > toNum; i--)
	{
		factorial *= i;
	}

	return factorial;
}