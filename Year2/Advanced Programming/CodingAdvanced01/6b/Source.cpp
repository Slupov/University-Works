#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		map<string, int> elementsCount;
		string el;
		for (int i = 0; i < n; ++i)
		{
			cin >> el;

			//contains such key
			if (elementsCount.find(el) != elementsCount.end())
			{
				elementsCount[el]++;
			}
			else
			{
				elementsCount.insert(std::pair<string, int>(el, 1));
			}
		}

		//find majorant
		string majorant = "";

		for (map<string, int>::iterator it = elementsCount.begin(); it != elementsCount.end(); ++it)
		{
			if (it->second > n / 2)
			{
				majorant = it->first;
				break;
			}
		}

		cout << majorant << endl;
	}


	return 0;
}
