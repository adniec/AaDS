#include <iostream>
#include "bst.hpp"
#include "tree.hpp"
#include "avl.hpp"
using namespace std;

int main(){
    node* tree = nullptr;
                                    insert(tree, 7);
            insert(tree, 4);                            insert(tree, 9);
    insert(tree, 1);        insert(tree, 5);    insert(tree, 8);        insert(tree, 12);
                                                                insert(tree, 11);   insert(tree, 13);
                                                                                        insert(tree, 15);
                                                                                            insert(tree, 18);
    cout << "Tree: ";
    print(tree);
    cout << "\n\nHeight: " << height(tree);
    cout << "\nSize: " << size(tree);
    cout << "\nLeaves: " << leaves(tree);
    cout << "\nNodes on level 2: " << nodesOnLevel(tree, 2);
    cout << "\nMinimum value: " << minimum(tree)->value;
    cout << "\nMaximum value: " << maximum(tree)->value;

    cout << "\n\nIs 12 in tree? " << isInTree(tree, 12);
    cout << "\nDelete 12.";
    deleteNode(tree, 12);
    cout << "\nSearch for node with value 12: " << search(tree, 12);
    cout << "\nIs it still Binary Search Tree? " << isBST(tree);

    cout << "\n\nIs tree AVL? " << isAVL(tree);
    cout << "\nBalance tree.";
    balanceBST(tree);
    cout << "\nNew root: " << tree->value;
    cout << "\nIs it AVL now? " << isAVL(tree);

    cout << "\n\nDelete nodes below level 1.";
    deleteBelow(tree, 1);
    cout << "\nTree: ";
    print(tree);
    deleteTree(tree);

    return 0;
}
