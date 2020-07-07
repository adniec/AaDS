#pragma once

struct node{
    int value;
    node* left = nullptr;
    node* right = nullptr;
};

node* minimum(node* root){
    if(root && root->left) return minimum(root->left);
    return root;
}

node* maximum(node* root){
    if(root && root->right) return maximum(root->right);
    return root;
}

void insert(node*& root, int number){
    if(!root){
        root = new node{number};
        return;
    }
    if(root->value >= number) insert(root->left, number);
    else insert(root->right, number);
}

node* search(node* root, int number){
    if(!root || root->value == number) return root;
    if(root->value > number) return search(root->left, number);
    return search(root->right, number);
}

node* deleteNode(node* root, int number){
    if(!root) return nullptr;

    if(number < root->value)
        root->left = deleteNode(root->left, number);
    else if(number > root->value)
        root->right = deleteNode(root->right, number);
    else{
        if(!root->left) return root->right;
        else if (!root->right) return root->left;

        int value = minimum(root->right)->value;
        root->value = value;
        root->right = deleteNode(root->right, value);
    }
    return root;
}

bool isBST(node* root, node* left=nullptr, node* right=nullptr){
    if(!root) return true;
    if(left && left->value > root->value) return false;
    if(right && right->value < root->value) return false;
    return isBST(root->left, left, root) && isBST(root->right, root, right);
}
