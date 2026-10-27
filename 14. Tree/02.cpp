// In question 1, define a constructor to initialise root pointer with NULL.

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
};

int main()
{
    BST tree;

    return 0;
}