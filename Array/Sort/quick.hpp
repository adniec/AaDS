#pragma once

void quickSort(int array[], int start, int end){
    int first = start;
    int last = end;
    int pivot = array[(first+last)/2];

    while(first <= last){
        while(array[first] < pivot) first++;
        while(array[last] > pivot) last--;
        if(first <= last) std::swap(array[last--], array[first++]);
    }
    if(start < last) quickSort(array, start, last);
    if(first < end) quickSort(array, first, end);
}
