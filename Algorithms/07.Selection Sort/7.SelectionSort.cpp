#include <iostream>
#include <vector>
using namespace std;

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

int min_position(vector<int> &a, int from, int to) {
    int min = from;
    for (int i = from + 1; i <= to; i++){
        if (a[i] < a[min]) min = i;
    }
    return min;
}


void selection_sort(vector<int> &a) {
    int i; /* the next position to be set to the minimum */
    for (i = 0; i < a.size() - 1; i++) {
        /* find the position of the minimum */
        int min = min_position(a, i, a.size() - 1);
        if (min != i) {
            swap(a[min], a[i]);
        }
    }
}

void print(vector<int> a) {
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    cout << "\n";
}

int main() {
    vector<int> v(20);
    for (int i = 0; i < v.size(); i++) {
        cin >> v[i];
    }

    print(v);
    selection_sort(v);
    print(v);
    return 0;
}