#pragma once

void merge(int array[], int start, int center, int end){
	int* helper = new int[end - start];
	int first = start;
	int mid = center + 1;
	int i = 0;

	while(first <= center && mid <= end){
		if(array[mid] < array[first]) helper[i] = array[mid++];
		else helper[i] = array[first++];
		i++;
	}
	while(first <= center) helper[i++] = array[first++];
	while(mid <= end) helper[i++] = array[mid++];

	for(i=0; i<=end-start; i++) array[start+i] = helper[i];
}

void mergeSort(int array[], int first, int last){
	if(first != last){
		int mid = (first + last) / 2;
		mergeSort(array, first, mid);
		mergeSort(array, mid+1, last);
		merge(array, first, mid, last);
	}
}
