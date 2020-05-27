#pragma once

int binarySearch(int array[], int length, int element){
	int first = 0;
	int last = length - 1;
	
	while(first <= last){
		int center = (first + last) / 2;
		if(array[center] < element){
			first = ++center;
		}else{
			last = --center;
		}
	}

	if(first < length && array[first] == element) return first;
	return -1;
}
