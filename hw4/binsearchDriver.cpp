/*
On my honour, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
Signed: Joowon Park
Section: 02
Student Number: 21600293
 * This program tests binary_search():
 *
 * The binary search algorithm is a method of searching a sorted array for a single
 * element by cutting the array in half with each recursive pass.The trick is to
 * pick a midpoint near the center of the array, compare the data at that point
 * with the data being searched and then responding to one of three possible
 * conditions : the data is found at the midpoint, the data at the midpoint is
 * greater than the data being searched for, or the data at the midpoint is less
 * than the data being searched for.
 * Recursion is used in this algorithm because with each pass a new array is
 * created by cutting the old one in half.The binary search procedure is then
 * called recursively, this time on the new (and smaller) array.
 * Typically, the array's size is adjusted by manipulating a beginning and
 * ending index. The algorithm exhibits a logarithmic order of growth because
 * it essentially divides the problem domain in half with each pass.
 *
 * In this example, you need an extra function at user's convenience since a
 * user may want to simply call the function with three parameters such as
 * binsearch(data, key, size).  Once you get the user's initial call,
 * then you call binary_search(data, key, lo, hi) recursively.
 *
 * To build this program:
 *  g++ binsearchDriver.cpp binsearch.cpp quicksort.cpp -o binsearch
 *
 * 2018/03/08	Creation
 * 2018/02/02	C++ Conversion
 */

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

void printList(int *list, int N, int max_print = 10, int per_line = 5);
void quickSort(int *a, int n);
int binary_search(int *list, int key, int size);

int main(int argc, char *argv[]) {
	setvbuf(stdout, NULL, _IONBF, 0);		// print out immediately if any
	setvbuf(stdin,  NULL, _IONBF, 0);		// read input immediately if any

	vector<int> list;
	string line;
	int keyin;
	cout << "Enter numbers to sort(q to quit): ";
	while (cin >> keyin) {
		list.push_back(keyin);
	}

	int N = list.size();
	cout << "\nUNSORTED[" << N << "]:\n";
	printList(&list[0], N);
	quickSort(&list[0], N);
	cout << "\nSORTED[" << N << "]:\n";
	printList(&list[0], N);

	srand((unsigned)time(NULL));	// comment out when debugging

	int key = rand() % (N-1);
	// get a random number to use as a key for testing the binary search.

	int index = binary_search(&list[0], key, N);
	int check = 0 ;

	cout << "\n\t" << key << " To Be Found.\n";


	for(int i=0; i<N; i++){
		if(key == list[i]){
			cout << "\t" << key << " is @list[" << index << "].\n";
			check = 1;
			break;
		}
	}
	if(check == 0) cout << "\t" << key << " is NOT @list[" << index << "].\n";

	// invoke bineary_search to find key in the list.
	// display the result


	// print a few data around a possible key index or -index to check your output.
	int extra = 8;						// a magic number

	int count = 0;
	int wIndex = index - 2;

	while(count < extra){
		if(wIndex < 0) {
			wIndex++;
			continue;
		}else if(wIndex > N-1){
			break;
		}
		cout << "\t[" << wIndex << "]=" << list[wIndex] << endl;
		wIndex++;
		count ++;
	}

	cout << "Happy Coding~~\n";
	// system("pause");
	return EXIT_SUCCESS;
}
