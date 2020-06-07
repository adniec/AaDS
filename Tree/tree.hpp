#pragma once
#include <iostream>
using namespace std;

int size(node* root){
    if(!root) return 0;
    return 1 + size(root->left) + size(root->right);
}

int height(node* root){
    if(!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}

int leaves(node* root){
    if(!root) return 0;
    if(!root->left && !root->right) return 1;
    return leaves(root->left) + leaves(root->right);
}

int nodesOnLevel(node* root, int level){
    if(!root) return 0;
    if(!level) return 1;
    return nodesOnLevel(root->left, level-1) + nodesOnLevel(root->right, level-1);
}

void print(node* root){
    if(root){
        print(root->left);
        cout << root->value << " ";
        print(root->right);
    }
}
