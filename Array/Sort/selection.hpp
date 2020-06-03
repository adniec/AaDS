#pragma once

void selectionSort(int array[], int length){
    for(int sorted=0; sorted < length-1; sorted++){
        int smallest = sorted;
        
        for(int i = sorted+1; i < length; i++)
            if(array[i] < array[smallest])
                smallest = i;
        
        std::swap(array[smallest], array[sorted]);
    }
}
