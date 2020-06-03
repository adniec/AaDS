#pragma once
#include <iostream>
#include "Sort/quick.hpp"
using namespace std;

const int N = 10;
int ARRAY[N];

void rotate(int array[], int length, int positions){
    if(length > 1)
        for(int i=0; i<positions%length; i++)
            for(int j=1; j<length; j++)
                swap(array[j-1], array[j]);
}

void print(int array[], int length=N){
    for(int i=0; i<length; i++)
        cout << array[i] << " ";
    cout << endl;
}

int* get(bool sorted=false){
    srand((unsigned)time(nullptr));

    for (int i=0; i<N; i++)
        ARRAY[i] = rand() / 10000000;
    if(sorted)
        quickSort(ARRAY, 0, N-1);
    return ARRAY;
}
