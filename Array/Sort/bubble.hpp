#pragma once

void bubbleSort(int array[], int length){
    for(int last=length-1; last>0; last--)
        for(int first=0; first<last; first++)
            if(array[first] > array[first+1])
                std::swap(array[first], array[first+1]);
}
