void quicksort(int array[], int firstIndex, int lastIndex){
	int first = firstIndex;
	int last = lastIndex;
	int midElement = array[(first+last)/2];
	while(first<=last){
		while(array[first]<midElement) first++;
		while(array[last]>midElement) last--;
		if(first<=last){
			int tmp=array[last];
			array[last]=array[first];
			array[first]=tmp;
			first++;
			last--;
		}
	}
	if(firstIndex<last)	quicksort(array, firstIndex, last);
	if(first<lastIndex) quicksort(array, first, lastIndex);
}
