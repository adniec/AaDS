void bubblesort(int array[], int len){	
	for(int reverseIndex=len - 1; reverseIndex>0; reverseIndex--){
		for(int index=0; index<reverseIndex; index++){
			if(array[index]>array[index+1]){
				int tmp=array[index];
				array[index]=array[index+1];
				array[index+1]=tmp;
			}	
		}
	}
}
