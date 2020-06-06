#pragma once

void insert(node*& head, node* element){
    if(!element) return;
    if(!head || head->value >= element->value){
        element->next = head;
        head = element;
        return;
    }

    node* n = head;
    while(n->next && n->next->value < element->value) n = n->next;
    element->next = n->next;
    n->next = element;
}

void insertionSort(node*& head){
    if(!head || !head->next) return;

    node* sorted = nullptr;
    node* element;

    while(head){
        element = head;
        head = head->next;
        insert(sorted, element);
    }
    head = sorted;
}
