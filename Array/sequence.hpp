#pragma once

int longestPositiveSequence(int array[], int length){
	int sequence = 0;
	int longest = 0;
	
	for(int i=0; i<length; i++){
		sequence += array[i];
		if(sequence < 0) sequence = 0;
		if(sequence > longest) longest = sequence;
	}
	return longest;
}
