void combsort(int array[], int len){
	int gap = len;
	bool swapped = true;
	
	while(gap>1 || swapped){
		gap=std::max(1,int(gap/1.3));
		swapped = false;
		
		for(int index=0;index<len-gap;index++){
			if(array[index]>array[index+gap]){
				int tmp = array[index];
				array[index] = array[index+gap];
				array[index+gap] = tmp;
				swapped = true;
			}
		}
	}
}
