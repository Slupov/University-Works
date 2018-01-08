#include<iostream>

using namespace std;

int main() {
    int r1, c1, r2, c2;
    cout << "Enter rows and columns of first matrix:";
    cin >> r1 >> c1;
    cout << "Enter rows and columns of second matrix:";
    cin >> r2 >> c2;
    int m1[r1][c1], m2[r2][c2];
    int res[r1][c2];
    int i, j, k;

    if (c1 != r2) {
        cout << "\nSorry!!!! Matrix multiplication can't be done";
        return 1;
    } else {
        cout << "\nEnter first matrix:\n";
        for (i = 0; i < r1; ++i)
            for (j = 0; j < c1; ++j)
                cin >> m1[i][j];

        cout << "\nEnter second matrix:\n";
        for (i = 0; i < r2; ++i)
            for (j = 0; j < c2; ++j)
                cin >> m2[i][j];

        cout << "\nThe new matrix is:\n";
        for (i = 0; i < r1; ++i) 
		{
            for (j = 0; j < c2; ++j) 
			{
                res[i][j] = 0;
                for (k = 0; k < c1; ++k)
                    res[i][j] += (m1[i][k] * m2[k][j]);
            }
            cout << "\n";
        }
    }

    return 0;
}