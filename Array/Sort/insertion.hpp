#pragma once

void insertionSort(int array[], int length){
    for(int i=1; i < length; i++){
        int value = array[i];
        int position = i;
        
        while(position > 0 && array[position-1] > value)
            array[position--] = array[position-1];
        array[position] = value;
    }
}
