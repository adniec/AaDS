#include <iostream>
#include "../array.hpp"
#include "bubble.hpp"
#include "comb.hpp"
#include "insertion.hpp"
#include "merge.hpp"
#include "quick.hpp"
#include "selection.hpp"
using namespace std;

int main(){
    int* array;

    cout << "BubbleSort:";
    cout << "\nArray : ";
    array = get();
    print(array);
    cout << "Sorted: ";
    bubbleSort(array, N);
    print(array);

    cout << "\nCombSort:";
    cout << "\nArray : ";
    array = get();
    print(array);
    cout << "Sorted: ";
    combSort(array, N);
    print(array);

    cout << "\nInsertionSort:";
    cout << "\nArray : ";
    array = get();
    print(array);
    cout << "Sorted: ";
    insertionSort(array, N);
    print(array);

    cout << "\nMergeSort:";
    cout << "\nArray : ";
    array = get();
    print(array);
    cout << "Sorted: ";
    mergeSort(array,0, N-1);
    print(array);

    cout << "\nQuickSort:";
    cout << "\nArray : ";
    array = get();
    print(array);
    cout << "Sorted: ";
    quickSort(array, 0, N-1);
    print(array);

    cout << "\nSelectionSort:";
    cout << "\nArray : ";
    array = get();
    print(array);
    cout << "Sorted: ";
    selectionSort(array, N);
    print(array);

    return(0);
}
