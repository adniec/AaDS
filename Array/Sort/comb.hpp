#pragma once

void combSort(int array[], int length){
    int gap = length;
    bool swapped = true;

    while(gap > 1 || swapped){
        gap = std::max(1, int(gap / 1.3));
        swapped = false;

        for(int i=0; i<length-gap; i++){
            if(array[i] > array[i+gap]){
                std::swap(array[i], array[i+gap]);
                swapped = true;
            }
        }
    }
}
