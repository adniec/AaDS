void selectionsort(int array[], int len){	
	for(int index = 0; index<len-1;index++){
		int indexOfLowest = index;
		for(int secondIndex = index+1; secondIndex<len;secondIndex++){
			if(array[secondIndex]<array[indexOfLowest]){
				indexOfLowest = secondIndex;
			}
		}
		int tmp = array[indexOfLowest];
		array[indexOfLowest] = array[index];
		array[index] = tmp;		
	}
}
