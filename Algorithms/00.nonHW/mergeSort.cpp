#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &a, int from, int mid, int to) {
    int n = to - from + 1; /* size of the range to be merged */
    /* merge both halves into a temporary vector b */
    vector<int> b(n);

    int i1 = from;
    /* next element to consider in the first half */
    int i2 = mid + 1;
    /* next element to consider in the second half */
    int j = 0; /* next open position in b */
    /*
       As long as neither i1 nor i2 is past the end, move the smaller
       element into b
    */
    while (i1 <= mid && i2 <= to) {
        if (a[i1] < a[i2]) {
            b[j] = a[i1];
            i1++;
        } else {
            b[j] = a[i2];
            i2++;
        }
        j++;
    }

    /*
       Note that only one of the two while loops below is executed
    */

    /* Copy any remaining entries of the first half */
    while (i1 <= mid) {
        b[j] = a[i1];
        i1++;
        j++;
    }
    /* Copy any remaining entries of the second half */
    while (i2 <= to) {
        b[j] = a[i2];
        i2++;
        j++;
    }

    /* Copy back from the temporary vector */
    for (j = 0; j < n; j++) a[from + j] = b[j];
}

void merge_sort(vector<int> &a, int from, int to) {
    if (from == to) return;
    int mid = (from + to) / 2;
    /* sort the first and the second half */
    merge_sort(a, from, mid);
    merge_sort(a, mid + 1, to);
    merge(a, from, mid, to);
}

void print(vector<int> a) {
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    cout << "\n";
}

int start_merge_sort() {
    vector<int> v(20);

    for (int i = 0; i < v.size(); i++) {
        cin >> v[i];
    }

    print(v);
    merge_sort(v, 0, v.size() - 1);
    print(v);
    return 0;
}