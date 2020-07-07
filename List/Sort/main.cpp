#include "../list.hpp"
#include "bubble.hpp"
#include "insertion.hpp"
#include "merge.hpp"
#include "selection.hpp"
#include <iostream>
using namespace std;

#define N 10

int main(){
    cout << "BubbleSort:";
    cout << "\nList  : ";
    node* bubble = get(N);
    print(bubble);
    cout << "Sorted: ";
    bubbleSort(bubble, N);
    print(bubble);

    cout << "\nInsertionSort:";
    cout << "\nList  : ";
    node* insertion = get(N);
    print(insertion);
    cout << "Sorted: ";
    insertionSort(insertion);
    print(insertion);

    cout << "\nMergeSort:";
    cout << "\nList  : ";
    node* merged = get(N);
    print(merged);
    cout << "Sorted: ";
    mergeSort(&merged);
    print(merged);

    cout << "\nSelectionSort:";
    cout << "\nList  : ";
    node* selection = get(N);
    print(selection);
    cout << "Sorted: ";
    selectionSort(selection);
    print(selection);

    return(0);
}
