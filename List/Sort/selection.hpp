#pragma once

void selectionSort(node*& head){
    if(!head || !head->next) return;

    node* n = head;
    node* parent = nullptr;
    int minimum = n->value;

    while(n->next){
        if(n->next->value < minimum){
            parent = n;
            minimum = n->next->value;
        }
        n = n->next;
    }

    if(parent){
        node* front = parent->next;
        parent->next = parent->next->next;
        front->next = head;
        head = front;
    }

    if(head->next) selectionSort(head->next);
}
