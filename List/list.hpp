#pragma once
#include <iostream>
using namespace std;

struct node{
    int value;
    node *next = nullptr;
};

void pushFront(node*& head, int number){
    head = new node{number, head};
}

void popFront(node*& head){
    if(head){
        node* tmp = head;
        head = head->next;
        delete tmp;
    }
}

void pushBack(node*& head, int number){
    if(!head) head = new node{number};
    else{
        node* n = head;
        while(n->next) n = n->next;
        n->next = new node{number};
    }
}

void popBack(node*& head){
    if(!head) return;
    else if(!head->next) popFront(head);
    else{
        node* n = head;
        while(n->next->next) n = n->next;
        node* tmp = n->next;
        n->next = nullptr;
        delete tmp;
    }
}

void remove(node*& head, int number){
    if(head){
        node* n = head->next;
        if(head->value == number){
            delete head;
            head=n;
            return;
        }
        node* prev = head;
        while(n){
            if(n->value == number){
                prev->next = n->next;
                delete n;
                return;
            }
            prev = n;
            n = n->next;
        }
    }
}

void reverse(node*& head){
    if(head && head->next){
        node* n = head->next;
        head->next = nullptr;
        while(n){
            node* tmp = n;
            n = n->next;
            tmp->next = head;
            head = tmp;
        }
    }
}

node* search(node* head, int element){
    if(!head) return nullptr;
    if(head->value == element) return head;
    return search(head->next, element);
}

bool isInList(node* head, int element){
    while(head){
        if(head->value == element) return true;
        head = head->next;
    }
    return false;
}

int minimum(node* n){
    int minimum = n->value;
    while(n){
        if(n->value < minimum) minimum = n->value;
        n = n->next;
    }
    return minimum;
}

int maximum(node* n){
    int maximum = n->value;
    while(n){
        if(n->value > maximum) maximum = n->value;
        n = n->next;
    }
    return maximum;
}

int length(node* head){
    if(!head) return 0;
    return 1 + length(head->next);
}

void print(node* n){
    while(n){
        cout << n->value << " ";
        n = n->next;
    }
    cout << endl;
}

node* get(int length){
    srand((unsigned)time(nullptr));
    node* head = nullptr;

    for(int i=0; i<length; i++)
        pushFront(head, rand() / 10000000);
    return head;
}
