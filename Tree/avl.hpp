#pragma once

bool isBalanced(node* root){
    if(!root) return true;
    if(abs(height(root->right) - height(root->left)) <= 1)
        if(isBalanced(root->left) && isBalanced(root->right))
            return true;
    return false;
}

bool isAVL(node* root){
    return isBST(root) && isBalanced(root);
}

int flatten(node*& root){
    if(!root) return 0;
    if(root->left){
        node* n = root;
        node* parent = root;

        while(n->left){
            parent = n;
            n = n->left;
        }
        parent->left = nullptr;

        node* maxi = maximum(n);
        maxi->right = root;

        root = n;
    }
    return 1 + flatten(root->right);
}

void balance(node*& root, int elements, bool right){
    if(!root || elements < 3) return;
    int counter = elements / 2;
    node* tmp;

    while(counter){
        tmp = root;
        if(right){
            root = root->right;
            tmp->right = nullptr;
            root->left = tmp;
        }else{
            root = root->left;
            tmp->left = nullptr;
            root->right = tmp;
        }
        counter--;
    }
    balance(root->left, elements/2, false);
    if(!(elements % 2)) elements--;
    balance(root->right, elements/2, true);
}

void balanceBST(node*& root){
    balance(root, flatten(root), true);
}
