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

void moveNegativeFront(int array[], int length){
	int index = 0;
	for(int i=0; i<length; i++)
		if(array[i] < 0)
			std::swap(array[index++], array[i]);
}

bool isSumOfTwoEqualNumber(int array[], int length, int number){
	for(int i=0; i<length; i++)
		for(int j=i+1; j<length; j++)
			if(array[i] + array[j] == number)
				return true;
	return false;
}
