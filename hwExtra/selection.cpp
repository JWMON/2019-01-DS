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
#include "sort.h"

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

using namespace std;

void selectionSort(int *list, int n, int (*comp)(int a, int b)) {
	int i, j, min, temp;
	for (i = 0; i < n - 1; i++) {
		min = i;
		for (j = i + 1; j < n; j++)
//			if ((list[j] < list[min]))
			if((*comp)(list[min], list[j])>0)
				min = j;
		// Swap min found with the first one of unsorted
		temp = list[i];
		list[i] = list[min];
		list[min] = temp;
	}

}
