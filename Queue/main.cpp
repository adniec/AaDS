#include <iostream>
#include "queue.hpp"

using namespace std;


int main(){
    queue q;

    cout << "Fill queue til last place with numbers from 0 to " << MAX-1 << endl;
    for(int i=0; i<MAX; i++) q.put(i);

    cout <<  "Is queue full? " << q.isFull() << endl;
    // q.put(100); // put on full queue will raise error

    cout << "Get and print first five elements from queue: ";
    for(int i=0; i<5; i++) cout << q.get() << " ";

    cout << endl << "Add five elements from " << MAX << " to " << MAX+4 << " on newly vacated places." << endl;
    for(int i=MAX; i<MAX+5; i++) q.put(i);

    cout << "Then get all elements except last ten." << endl;
    for(int i=0; i<MAX-10; i++) q.get();

    cout << "Finally get and print last ten elements: ";
    while(!q.isEmpty()) cout << q.get() << " ";

    cout << endl << "Is queue empty? " << q.isEmpty() << endl;
    // q.get(); // get on empty queue will raise error

    return 0;
}
