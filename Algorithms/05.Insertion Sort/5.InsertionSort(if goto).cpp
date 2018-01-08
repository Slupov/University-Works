#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	const int N = 5;
	int arr[N] = { 31,34,12,22,11 };

	int i = 1;
label1:
	if (i < N)
	{
		//at is insert position
		int at = i;

		label2:
		if (at > 0 && arr[at] < arr[at - 1])
		{
			//swap
			int temp = arr[at];
			arr[at] = arr[at - 1];
			arr[at - 1] = temp;
			at--;
			i++;
			goto label2;
		}
		else 
		{
			i++;
			goto label1;
		}
	}

	for (int i = 0; i < N; i++) 
	{
		cout << arr[i] << endl;
	}
	return 0;
}
