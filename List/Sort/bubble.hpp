#pragma once

void bubbleSort(node*& head, int length){
    if(!head || !head->next || length < 2) return;
    node* n = head;
    int counter = length - 1;
    while(n->next && counter){
        if(n->value > n->next->value)
            std::swap(n->value, n->next->value);
        n = n->next;
        counter--;
    }
    bubbleSort(head, --length);
}
