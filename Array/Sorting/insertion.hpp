void insertionsort(int array[], int len){	
	for(int index=1; index<len; index++){
		int currentValue = array[index];
		int position = index;
		while(position>0 && array[position-1]>currentValue){
			array[position] = array[position-1];
			position --;
		}
		array[position] = currentValue;
	}
}
