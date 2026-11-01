// In question 1, define a method to get balance factor of a node. 

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

    // Get height of a node
    int getHeight(node* temp)
    {
        if (temp == NULL)
        {
            return 0;
        }

        return temp->height;
    }

    // Get balance factor of a node
    int getBalanceFactor(node* temp)
    {
        if (temp == NULL)
        {
            return 0;
        }

        return getHeight(temp->left) -
               getHeight(temp->right);
    }

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