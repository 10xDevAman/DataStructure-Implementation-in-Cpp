// Define a class BST (Binary Search Tree) with node type pointer root as member variable. Implement Binary Search Tree using linked representation.

#include <iostream>
using namespace std;

class BST
{
private:
    struct node
    {
        int data;
        node* left;
        node* right;
    };

    node* root;
};

int main()
{
    BST tree;

    return 0;
}