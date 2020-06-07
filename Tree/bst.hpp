#pragma once

struct node{
    int value;
    node* left = nullptr;
    node* right = nullptr;
};

void insert(node*& root, int number){
    if(!root){
        root = new node{number};
        return;
    }
    if(root->value >= number) insert(root->left, number);
    else insert(root->right, number);
}

bool isBST(node* root, node* left=nullptr, node* right=nullptr){
    if (!root) return true;
    if (left && left->value > root->value) return false;
    if (right && right->value < root->value) return false;
    return isBST(root->left, left, root) && isBST(root->right, root, right);
}
