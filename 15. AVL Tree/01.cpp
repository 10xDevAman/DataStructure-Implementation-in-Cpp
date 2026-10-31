// Define a class AVL, with node type pointer root as member variable. Implement AVL tree using linked representation

#include <iostream>
using namespace std;

class AVL
{
private:
    struct node
    {
        int data;
        int height;
        node* left;
        node* right;
    };

    node* root;
};

int main()
{
    AVL tree;

    return 0;
}