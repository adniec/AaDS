#pragma once

node* merge(node* first, node* second){
    node* merged = nullptr;

    if(!first) return second;
    if(!second) return first;

    if(first->value <= second->value){
        merged = first;
        merged->next = merge(first->next, second);
    }else{
        merged = second;
        merged->next = merge(first, second->next);
    }
    return merged;
}

void split(node* source, node** front, node** middle){
    node* n = source->next;
    node* mid = source;

    while(n){
        n = n->next;
        if(n){
            mid = mid->next;
            n = n->next;
        }
    }
    *front = source;
    *middle = mid->next;
    mid->next = nullptr;
}

void mergeSort(node** list){
    node* head = *list;
    node* n;
    node* mid;

    if(!head || !head->next) return;

    split(head, &n, &mid);
    mergeSort(&n);
    mergeSort(&mid);

    *list = merge(n, mid);
}
