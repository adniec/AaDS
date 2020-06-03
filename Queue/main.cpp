#include <iostream>
#include "queue.hpp"
using namespace std;

int main(){
    queue q;

    cout << "Fill queue til last place with numbers from 0 to " << MAX-1;
    for(int i=0; i<MAX; i++) q.put(i);

    cout << "\nIs queue full? " << q.isFull();
    // q.put(100); // put on full queue will raise error

    cout << "\nGet and print first five elements from queue: ";
    for(int i=0; i<5; i++) cout << q.get() << " ";

    cout << "\nAdd five elements from " << MAX << " to " << MAX+4 << " on newly vacated places.";
    for(int i=MAX; i<MAX+5; i++) q.put(i);

    cout << "\nThen get all elements except last ten.";
    for(int i=0; i<MAX-10; i++) q.get();

    cout << "\nFinally get and print last ten elements: ";
    while(!q.isEmpty()) cout << q.get() << " ";

    cout << "\nIs queue empty? " << q.isEmpty();
    // q.get(); // get on empty queue will raise error

    return 0;
}
