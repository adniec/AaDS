#pragma once

#define SIZE 100

struct node{
    std::string key;
    int value;
    node* next = nullptr;
};

unsigned int strToNum(std::string str){
    unsigned int result = 0;
    for(int i=0; i<str.size(); i++)
        result ^= (int) str[i] << (i % 4) * 8;
    return result;
}

node* search(node* hashtab[SIZE], std::string key){
    int index = strToNum(key) % SIZE;
    node* n = hashtab[index];
    while(n){
        if(n->key == key) return n;
        n = n->next;
    }
    return nullptr;
}

void insert(node* hashtab[SIZE], std::string key, int value){
    node* found = search(hashtab, key);
    if(found)
        found->value = value;
    else{
        int index = strToNum(key) % SIZE;
        hashtab[index] = new node{key, value, hashtab[index]};
    }
}
