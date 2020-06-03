#include <iostream>
#include "anagrams.hpp"
#include "array.hpp"
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
    cout << "\n Array : ";
    print(array);
    return array;
}

void search(int index, bool recurrent=false){
    int* array = prepare(true);
    int element = 1000000;

    if(index < 0 || index >= N)
        cout << " Looking for " << element << " which is not in array...";
    else{
        element = array[index];
        cout << " Looking for " << element << " which is on position " << index << "...";
    }

    if(recurrent)
        cout << "\n Recurrent search result: " << binarySearchRecurrent(array, 0, N-1, element) << endl;
    else
        cout << "\n Search result: " << binarySearch(array, N, element) << endl;
}

int main(){
    cout << "Sequences:";
    int* array = prepare(false, true);
    cout << " Longest positive subsequence: " << longestPositiveSequence(array, N);

    int number = -210;
    int result = isSumOfTwoEqualNumber(array, N, number);
    cout << "\n Is sum of two array elements equal to " << number  << "? " << result;

    cout << "\n\n Moving all negative numbers to front...\n Array : ";
    moveNegativeFront(array, N);
    print(array);

    cout << "\n Rotating array by 3 positions...\n Array : ";
    rotate(array, N, 3);
    print(array);

    cout << "\nBinary search:";
    search(2);
    search(9, true);
    search(-1);

    cout << "\nAnagrams:";
    cout << "\n Are algorithm and logarithm anagrams? " << anagrams("algorithm", "logarithm");
    cout << "\n Are function and sequence anagrams? " << anagrams("function", "sequence");

    return(0);
}
