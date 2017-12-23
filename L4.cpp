// L4.cpp : Defines the entry point for the console application.
//
#include "stdio.h"
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
	for (int elementOfRow = 0; elementOfRow < size; elementOfRow++) array[elementOfRow] = new int[size];
	cout << "Enter matrix>>\n";
	for (int elementOfRow = 0; elementOfRow < size; elementOfRow++) {

		for (int elementOfColumn = 0; elementOfColumn < size; elementOfColumn++) {
			cin >> array[elementOfRow][elementOfColumn];

		}
	}

}

void Matrix::OutputMatrix() {

	for (int elementOfRow = 0; elementOfRow < size; elementOfRow++) {

		for (int elementOfColumn = 0; elementOfColumn < size; elementOfColumn++) {
			printf("%5d", array[elementOfRow][elementOfColumn]);

		}
		cout << endl;
	}

}

void Matrix::insertionSort()
{
	int temp, item;
	for (int elementOfRow = 0; elementOfRow < size; elementOfRow++)
		for (int elemtntOfColumn = 1; elementOfColumn < size; elementOfColumn++) {
			{
				temp = array[elementOfRow][elementOfColumn];
				item = elementOfColumn - 1;
				while (item >= 0 && array[elementOfRow][item] > temp)
				{
					array[elemntOfRow][item + 1] = array[elementOfRow][item];
					array[elementOfRow][item] = temp;
					item--;
				}
			}
		}
}
void Matrix::MathmeticActions() {

	int sum = 0;
	long product = 1;
	int elementOfColumn;
	for (elementOfColumn = 1; elementOfColumn < size; elementOfColumn++) {
		sum = 0;
		for (int elementOfRow = 0; elementOfRow < size; elementOfRow++) {

			if ((elementOfRow + elementOfColumn) >= size) {

				sum += array[elementOfRow][elementOfColumn];
			}
		}
		cout << " Sum of the " << elementOfColumn + 1 << " column: " << sum << endl;
		product *= sum;
	}
	float geometricAverage = pow(fabs(product), (1. / elementOfColumn));

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
