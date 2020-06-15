#include "list.hpp"
#include <iostream>
using namespace std;

int main(){
    node* list = nullptr;

    cout << "Create list.\nPush 3, 2, 1 to front.    List: ";
    pushFront(list, 3);
    pushFront(list, 2);
    pushFront(list, 1);
    print(list);

    cout << "Pop front and back.       List: ";
    popFront(list);
    popBack(list);
    print(list);

    cout << "Push 4, 6, 8 back.        List: ";
    pushBack(list, 4);
    pushBack(list, 6);
    pushBack(list, 8);
    print(list);

    cout << "Reverse list.             List: ";
    reverse(list);
    print(list);

    cout << "Remove 4 from list.       List: ";
    remove(list, 4);
    print(list);

    cout << "\nList length : " << length(list);
    cout << "\nMinimum value stored in list: " << minimum(list);
    cout << "\nMaximum value stored in list: " << maximum(list);
    cout << "\nIs 6 stored in list? " << isInList(list, 6);

    return(0);
}
