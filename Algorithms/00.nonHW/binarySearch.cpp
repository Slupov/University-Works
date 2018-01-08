#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

int binary_search(vector<int> v, int from, int to, int a)
{  if (from > to) return -1;
    int mid = (from + to) / 2;
    if (v[mid] == a) return mid;
    else if (v[mid] < a)
        return binary_search(v, mid + 1, to, a);
    else
        return binary_search(v, from, mid - 1, a);
}

void print(vector<int> a)
{  for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    cout << "\n";
}

void rand_seed()
{  int seed = static_cast<int>(time(0));
    srand(seed);
}

int rand_int(int a, int b)
{  return a + rand() % (b - a + 1);
}

int main()
{
    rand_seed();
    vector<int> v(20);
    v[0] = 1;
    for (int i = 1; i < v.size(); i++)
        v[i] = v[i - 1] + rand_int(1, 10);

    print(v);
    cout << "Enter number to search for: ";
    int n;
    cin >> n;
    int j = binary_search(v, 0, v.size() - 1, n);
    cout << "Found in position " << j << "\n";
    return 0;
}