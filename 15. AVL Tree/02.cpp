// In question 1, define constructor to initialise member variable.

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

public:
    // Constructor
    AVL()
    {
        root = NULL;
    }
};

int main()
{
    AVL tree;

    return 0;
}