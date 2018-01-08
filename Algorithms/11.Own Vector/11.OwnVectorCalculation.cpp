#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <string>

using namespace std;
#define SIZE 3

double** multiplyMatrices(double** m1, double** m2)
{
	double** res = new double*[SIZE];
	for (int i = 0; i < SIZE; ++i)
		res[i] = new double[SIZE]; //initialize every row

	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			res[i][j] = 0;
			for (int k = 0; k < SIZE; ++k)
			{
				res[i][j] += (m1[i][k]) * (m2[k][j]);
			}
		}
	}

	return res;
}

void printMatrix(double** matrix)
{
	cout << string(25, '-') << endl;
	cout << "The new matrix is:" << endl;

	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			cout << fixed << setprecision(3) << setw(4) << left << matrix[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;
}

void printOwnVector(vector<double>& ownV)
{
	cout << "Own vector: " << endl;
	for (int i = 0; i < ownV.size(); ++i)
	{
		cout << "|" << left << setw(5) << ownV[i] << "|" << endl;
	}
}

vector<double> calculate_ownV(double** matrix)
{
	vector<double> ownV(SIZE);
	double wholeSum = 0;

	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			wholeSum += matrix[i][j];
		}
	}

	for (int i = 0; i < SIZE; ++i)
	{
		double currentRowSum = 0;

		for (int j = 0; j < SIZE; ++j)
		{
			currentRowSum += matrix[i][j];
		}

		ownV[i] = currentRowSum / wholeSum;
	}

	return ownV;
}

bool areVectorsEqual(vector<double> v1, vector<double> v2, double epsilon)
{
	for (int i = 0; i < v1.size(); ++i)
	{
		if (abs(v2[i] - v1[i]) > epsilon)
		{
			return false;
		}
	}
	return true;
}

//own vector calculation
int main()
{
	double** matrix = new double*[SIZE];
	for (int i = 0; i < SIZE; ++i)
	{
		matrix[i] = new double[SIZE];
		cout << "Enter row " << i << endl;
		for (int j = 0; j < SIZE; ++j)
		{
			cin >> matrix[i][j];
		}
	}

	double epsilon;

	cout << "Enter epsilon precision for the own vector difference: ";
	cin >> epsilon;

	vector<double> ownV(SIZE);
	vector<double> ownV2(SIZE);

	double** res = multiplyMatrices(matrix, matrix);
	ownV2 = calculate_ownV(res);

	printMatrix(res);
	printOwnVector(ownV);

	int it = 1;
	do
	{
		res = multiplyMatrices(res, res);
		printMatrix(res);

		ownV = ownV2;
		ownV2 = calculate_ownV(res);
		printOwnVector(ownV2);

		it++;
	}
	while (!areVectorsEqual(ownV, ownV2, epsilon));

	cout << "Program ended with " << it << " vector calculations.\n";
	return 0;
}
