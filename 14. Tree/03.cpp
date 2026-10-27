// In question 1, define a method to check if the tree is empty.

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

public:
    // Constructor
    BST()
    {
        root = NULL;
    }

    // Check whether tree is empty
    bool isEmpty()
    {
        return root == NULL;
    }
};

int main()
{
    BST tree;

    if (tree.isEmpty())
    {
        cout << "Tree is empty." << endl;
    }
    else
    {
        cout << "Tree is not empty." << endl;
    }

    return 0;
}