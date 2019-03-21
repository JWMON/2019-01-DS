/*
On my honour, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
Signed: Joowon Park
Section: 02
Student Number: 21600293
*/
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include "nowic.h"
#include "sort.h"

using namespace std;

void print_list(int *list, int n) {
	for (int i = 0; i < n; i++)
		cout << list[i] << " ";
	cout << endl;
}

int ascending(int a, int b){
	return a-b;
}
int descending(int a, int b){
	return b-a;
}


void (*sortFn[])(int *, int, int (*comp)(int a, int b)) = {bubbleSort, quickSort, selectionSort, insertionSort};

#if 1
int main(int argc, char *argv[]) {

	int N = GetInt("Enter input sample size: ");

  int *list = new (nothrow)int[N];
  assert(list != NULL);

  srand((unsigned)time(NULL));

	for (int i = 0; i < N; i++)
		list[i] = rand() % N;

  int count;

	char sortList[][20] = {"BUBBLE", "QUICK", "SELECTION", "INSERTION"};

	cout << "Test Case: Not passing a default argument: quickSort(list, N)" << endl;
	cout << "-------------------------------------------------------------" << endl;
	cout << "NOTsorted: ";
	print_list(list, N);
	quickSort(list, N);
	cout << "   sorted: ";
	print_list(list, N);
	cout << endl;

	cout << "Test Case: Passing a function pointer: quickSort(list, N, up)" << endl;
	cout << "-------------------------------------------------------------" << endl;
	cout << "NOTsorted: ";
	print_list(list, N);
	quickSort(list, N, ascending);
	cout << "   sorted: ";
	print_list(list, N);
	cout << endl;

	cout << "Test Case: Passing a function pointer: quickSort(list, N, dn)" << endl;
	cout << "-------------------------------------------------------------" << endl;
	cout << "NOTsorted: ";
	print_list(list, N);
	quickSort(list, N, descending);
	cout << "   sorted: ";
	print_list(list, N);
	cout << endl;

	cout << "Test Case: Using an array of function pointers" << endl;
	cout << "----------------------------------------------" << endl;

  for(count=0; count<4; count++){
		for (int i = 0; i < N; i++)
	    list[i] = rand() % N;
		cout << "NOTsorted[" << sortList[count] << "]: " ;
	 	print_list(list, N);
    sortFn[count](list, N, ascending);
		cout << "UP sorted[" <<sortList[count] << "]: ";
		print_list(list, N);
		sortFn[count](list, N, descending);
		cout << "DN sorted[" << sortList[count] << "]: ";
		print_list(list, N);
		cout << endl;
  }

  delete[] list;
	system("pause");

}
#endif
