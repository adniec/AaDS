#include <iostream>
#include "hashtab.hpp"
using namespace std;

void print(node* hashtab[SIZE], int index){
    cout << "\nGet all elements under [" << index << "] index: ";
    node* n = hashtab[index];
    if(!n) cout << "nothing found.";

    while(n){
        cout << "'" << n->key << "': " << n->value << ", ";
        n = n->next;
    }
}

int main(){
    node* hashtab[SIZE] = {nullptr};

    const int N = 6;
    string words[N] = {"new", "expected", "example", "delete", "process", "accomplishment"};

    cout << "Insert new elements to hash table:\n";
    for(int i=0; i<N; i++){
        cout << " [" << strToNum(words[i]) % SIZE << "] '" << words[i] << "': " << i << "\n";
        insert(hashtab, words[i], i);
    }
    print(hashtab, 50);

    cout << "\nRemove key 'process'.";
    removeKey(hashtab, "process");
    print(hashtab, 69);

    cout << "\nRemove key 'delete'.";
    removeKey(hashtab, "delete");
    print(hashtab, 20);

    cout << "\n\nIs 'random' key in hash table? " << search(hashtab, "random");
    cout << "\nSearch for 'example' value in hash table: " << search(hashtab, "example")->value;

    return 0;
}
