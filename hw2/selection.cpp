// csort.cpp
// This is a sample code that runs okay, has a bad coding style.
// Reference: Fundamentals of Data Structures by Horowitz, Sahni
//
// When you compile the following code in Visual Studio, you may
// get the warning about scanf() or others. Then enter an addtional
// compiler option /wd4996 in the following:
// Project Properties -> C/C++ -> Command Line -> Additonal Options

#include <iostream>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;

#define SWAP(x, y, t)  ((t) = (x), (x) = (y), (y) = (t))

void selectionSort(int[], int);

/*
int main(int argc, char *argv[]) {

	int i, n, numOfSamples;

	if(argc == 1)
		while(1){
			cout << "Enter the number of samples: ";
			cin >> numOfSamples;

			if(numOfSamples >= 0)
				break;
			else
				cout << "Expecting a number larger than 0\n";
		}
	else
		numOfSamples = atoi(argv[1]);

	int *list = new (nothrow) int[numOfSamples];
	assert(list != nullptr);

	cout << "\nUnSorted array:\n";
	for (i = 0; i < numOfSamples; i++) {       // randomly generate numbers
		list[i] = rand() % 1000;
		cout << list[i] << "  ";
	}

	selectionSort(list, numOfSamples);

	cout << "\nSorted array:\n";
	for (i = 0; i < numOfSamples; i++) {
		cout << list[i] << "  ";
	}
	cout << "\n";

	return EXIT_SUCCESS;
}

*/
void selectionSort(int list[], int n) {
	int i, j, min, temp;
	for (i = 0; i < n - 1; i++) {
		min = i;
		for (j = i + 1; j < n; j++)
			if (list[j] < list[min])
				min = j;
		SWAP(list[i], list[min], temp);
	}
	
}
