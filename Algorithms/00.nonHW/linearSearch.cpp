#include <iostream>
#include <vector>
using namespace std;

int linear_search(vector<int> v, int a)
{  for (int i = 0; i < v.size(); i++)
      if (v[i] == a) return i;
   return -1;
}

void print(vector<int> a)
{  for (int i = 0; i < a.size(); i++)
      cout << a[i] << " ";
   cout << "\n";
}

int main()
{
   vector<int> v(20);
   for (int i = 0; i < v.size(); i++){
       cin >>v[i];
   }
   print(v);
   cout << "Enter number to search for: ";
   int n;
   cin >> n;
   int j = linear_search(v, n);
   cout << "Found in position " << j << "\n";
   return 0;
}