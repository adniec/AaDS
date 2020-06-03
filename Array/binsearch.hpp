#pragma once

int binarySearch(int array[], int length, int element){
    int first = 0;
    int last = length - 1;

    while(first <= last){
        int mid = (first + last) / 2;
        if(array[mid] < element) first = ++mid;
        else last = --mid;
    }
    if(first < length && array[first] == element) return first;
    return -1;
}

int binarySearchRecurrent(int array[], int first, int last, int element){
    int mid = (first + last) / 2;

    if(array[mid] == element) return mid;
    if(first == last) return -1;

    if(element < array[mid])
        return binarySearchRecurrent(array, first, --mid, element);
    return binarySearchRecurrent(array, ++mid, last, element);
}
