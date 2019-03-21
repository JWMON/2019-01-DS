#ifndef SORT_H
#define SORT_H

int ascending(int a, int b);
int descending(int a, int b);

void bubbleSort(int *list, int n, int (*comp)(int a, int b)= ascending);
void insertionSort(int *list, int n, int (*comp)(int a, int b)= ascending);
void quickSort(int *list, int n, int (*comp)(int a, int b)= ascending);
void selectionSort(int *list, int n, int (*comp)(int a, int b)= ascending);

#endif
