#include <iostream>
using namespace std;

//selection sort
int main() {
    const int N = 5;
    int arr[N] = {31, 34, 12, 22, 11};

    int i = 0, j;
    label:
    if (i < N) {
        int min = arr[i];
        int index = i;
        j = i + 1;

        label2:
        if (j < N) {
            if (arr[j] < min) {
                min = arr[j];
                index = j;
            }
            j++;
            goto label2;
        }
        else {
            int temp = arr[i];
            arr[i] = min;
            arr[index] = temp;
            i++;
            goto label;
        }
    }

    for (int i = 0; i < N; i++) {
        cout << arr[i] << endl;
    }
    return 0;
}
