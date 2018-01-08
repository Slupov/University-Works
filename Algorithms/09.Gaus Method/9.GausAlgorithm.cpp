#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;//n is the number of unknowns
    cout << "n: ";
    cin >> n;
    float **matrix;
    matrix = new float *[n];

    for (int i = 0; i < n; i++) {
        matrix[i] = new float[n + 1];
    }
    cout << '\n';

    for (int r = 0; r < n; r++)//Get the array elements from the user
    {
        for (int c = 0; c < n + 1; c++) {
            cout << "matrix[" << r + 1 << "]" << "[" << c + 1 << "] :";
            cin >> matrix[r][c];
        }
    }
    cout << '\n';
    for (int r = 0; r < n; r++)//Display the array on the console screen
    {
        for (int c = 0; c < n + 1; c++) {
            cout << " " << matrix[r][c] << " ";
        }
        cout << '\n';
    }

    //Gaus algorithm
    for (int a = 0; a < n; a++) {
        //gets diagonal element
        float dElement = matrix[a][a];
        //divide the whole row by its diagonal element
        for (int x = 0; x < n + 1; x++) {
            matrix[a][x] = matrix[a][x] / dElement;
        }
//region topBottonZeros
//        // make the elements over and under the diagonal one zeros
//        for (int i = 0; i < n; i++) {
//            float toZero = matrix[i][a];
//            for (int j = 0; j < n + 1; j++) {
//                if (i == a)break;
//                matrix[i][j] = matrix[i][j] - matrix[a][j] * toZero;
//            }
//        }
//endregion
        // make the elements  under the diagonal one zeros
        for (int i = a + 1; i < n; i++) {
            float toZero = matrix[i][a];
            for (int j = 0; j < n + 1; j++) {
                //multiplying currrent pivot row (a) by first element
                //of current iteration row and subtract it from all
                //elements on current iteration row (i)
                matrix[i][j] = matrix[i][j] - matrix[a][j] * toZero;
            }
        }
    }
    cout << "Solution of the system:" << '\n' << '\n';
    for (int r = 0; r < n; r++)//The result after apllying the gauss algorithm
    {
        for (int c = 0; c < n + 1; c++) {
            cout << " " << matrix[r][c] << " ";
        }
        cout << '\n';
    }

}