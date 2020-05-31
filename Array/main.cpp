#include <iostream>
#include "array.hpp"
#include "anagrams.hpp"
#include "binsearch.hpp"
#include "sequence.hpp"
using namespace std;

int* prepare(bool sorted=false, bool negative=false){
	int* array = get(sorted);
	if(negative){
		array[N/3] = -10;
		array[N/2] = -200;
		array[2*N/3] = -1000;
	}
	cout << endl << " Array : ";
	print(array);
	return array;
}

void search(int index, bool recurrent=false){
	int* array = prepare(true);
	int element = 1000000;

	if(index < 0 || index >= N){
		cout << " Looking for " << element << " which is not in array... ";
	}else{
		element = array[index];
		cout << " Looking for " << element << " which is on position " << index << "... ";
	}

	if(recurrent){
		cout << endl << " Recurrent search result: " << binarySearchRecurrent(array, 0, N-1, element) << endl;
	}else{
		cout << endl << " Search result: " << binarySearch(array, N, element) << endl;
	}
}

int main()
{
	cout << "Sequences:";
	int* array = prepare(false, true);
	cout << " Longest positive subsequence: " << longestPositiveSequence(array, N) << endl;

	int number = -210;
	cout << " Is sum of two array elements equal to " << number  << "? " 
	<< isSumOfTwoEqualNumber(array, N, number) << endl;

	cout << endl << " Moving all negative numbers to front..." << endl << " Array : ";
	moveNegativeFront(array, N);
	print(array);

	cout << endl << " Rotating array by 3 positions..." << endl << " Array : ";
	rotate(array, N, 3);
	print(array);

	cout << endl << "Binary search:";
	search(2);
	search(9, true);
	search(-1);

	cout << endl << "Anagrams:" << endl;
	cout << " Are algorithm and logarithm anagrams? " << anagrams("algorithm", "logarithm") << endl;
	cout << " Are function and sequence anagrams? " << anagrams("function", "sequence") << endl;

    return(0);
}
