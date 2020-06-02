#include <iostream>
#include "bubble.hpp"
#include "comb.hpp"
#include "insertion.hpp"
#include "merge.hpp"
#include "quick.hpp"
#include "selection.hpp"
#include "../array.hpp"
using namespace std;

int main()
{
	int* array;

	cout << "BubbleSort:" << endl;
	cout << "Array : ";
	array = get();
	print(array);
	cout << "Sorted: ";
	bubbleSort(array, N);
    print(array);

	cout << endl << "CombSort:" << endl;
	cout << "Array : ";
	array = get();
	print(array);
	cout << "Sorted: ";
	combSort(array, N);
    print(array);

	cout << endl << "InsertionSort:" << endl;
	cout << "Array : ";
	array = get();
	print(array);
	cout << "Sorted: ";
	insertionSort(array, N);
    print(array);

	cout << endl << "MergeSort:" << endl;
	cout << "Array : ";
	array = get();
	print(array);
	cout << "Sorted: ";
	mergeSort(array,0, N-1);
    print(array);

	cout << endl << "QuickSort:" << endl;
	cout << "Array : ";
	array = get();
	print(array);
	cout << "Sorted: ";
	quickSort(array, 0, N-1);
    print(array);

	cout << endl << "SelectionSort:" << endl;
	cout << "Array : ";
	array = get();
	print(array);
	cout << "Sorted: ";
	selectionSort(array, N);
    print(array);

    return(0);
}
