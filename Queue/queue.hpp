#pragma once

const int MAX = 100;

struct queue{
    int arr[MAX];
    int first, last;

    queue();
    void put(int element);
    int get();
    bool isEmpty();
    bool isFull();
};

queue::queue(){first=0; last=0;};

void queue::put(int element){
    if(!isFull()){
        arr[last++ % MAX] = element;
        return;
    }
    throw std::exception();
}

int queue::get(){
    if(!isEmpty())
        return arr[first++ % MAX];
    throw std::exception();
}

bool queue::isEmpty(){
    return first == last;
}

bool queue::isFull(){
    return first + MAX == last;
}
