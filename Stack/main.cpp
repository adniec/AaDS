#include <iostream>
#include "stack.hpp"
using namespace std;

int main(){
    stack s;

    cout <<  "Is stack empty? " << s.isEmpty();
    // s.pop(); // pop on empty stack will raise error

    cout << "\nFill stack til last place with numbers from 0 to " << MAX-1;
    for(int i=0; i<MAX; i++) s.push(i);

    cout <<  "\nIs stack full? " << s.isFull();
    // s.push(100); // push on full stack will raise error

    cout << "\nPop and print five lastly pushed elements to stack: ";
    for(int i=0; i<5; i++) cout << s.pop() << " ";

    cout << "\nAdd five elements from 0 to 4 on newly vacated places.";
    for(int i=0; i<5; i++) s.push(i);

    cout << "\nPop and print ten elements from stack: ";
    for(int i=0; i<10; i++) cout << s.pop() << " ";

    return 0;
}
