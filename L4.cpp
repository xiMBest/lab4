// L4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "conio.h"
#include "iostream"
#include "math.h"

using namespace std;


class Matrix
{

private:
	int **array;
	int size;
public:

	void InputMatrix();
	void OutputMatrix();
	void MathmeticActions();
	void insertionSort();
};

void Matrix::InputMatrix() {

	cout << "Enter size of matrix>>";
	cin >> size;
	array = new int *[size];
	for (int i = 0; i < size; i++) array[i] = new int[size];
	cout << "Enter matrix>>\n";
	for (int i = 0; i < size; i++) {

		for (int j = 0; j < size; j++) {
			cin >> array[i][j];

		}
	}

}

void Matrix::OutputMatrix() {

	for (int i = 0; i < size; i++) {

		for (int j = 0; j < size; j++) {
			printf("%5d", array[i][j]);

		}
		cout << endl;
	}

}

void Matrix::insertionSort()
{
	int temp, item;
	for (int i = 0; i < size; i++)
		for (int j = 1; j < size; j++) {
			{
				temp = array[i][j];
				item = j - 1;
				while (item >= 0 && array[i][item] > temp)
				{
					array[i][item + 1] = array[i][item];
					array[i][item] = temp;
					item--;
				}
			}
		}
}
void Matrix::MathmeticActions() {

	int sum = 0;
	long product = 1;
	int j;
	for (j = 1; j < size; j++) {
		sum = 0;
		for (int i = 0; i < size; i++) {

			if ((i + j) >= size) {

				sum += array[i][j];
			}
		}
		cout << " Sum of the " << j + 1 << " column: " << sum << endl;
		product *= sum;
	}
	float geometricAverage = pow(fabs(product), (1. / j));

	cout << "Geometric average = " << geometricAverage << endl;

}


int _tmain(void)
{
	Matrix A;
	A.InputMatrix();
	cout << "Matrix=>>\n";
	A.OutputMatrix();

	A.insertionSort();
	cout << "Sorted matrix=>>" << endl;
	A.OutputMatrix();
	A.MathmeticActions();


	system("pause");
	return 0;
}