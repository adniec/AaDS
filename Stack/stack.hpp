#pragma once

const int MAX = 100;

struct stack{
    int arr[MAX];
    int size;

    stack();
    void push(int element);
    int pop();
    bool isEmpty();
    bool isFull();
};

stack::stack(){size = 0;}

void stack::push(int element){
    if(!isFull()){
        arr[size++] = element;
        return;
    }
    throw std::exception();
}

int stack::pop(){
    if(!isEmpty())
        return arr[--size];
    throw std::exception();
}

bool stack::isEmpty(){
    return size==0;
}

bool stack::isFull(){
    return size == MAX;
}
