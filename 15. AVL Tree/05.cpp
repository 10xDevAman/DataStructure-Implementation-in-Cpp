// In question 1, define a method rightRotate for clockwise rotation 

#include <iostream>
#include <algorithm>
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

    // Get balance factor
    int getBalanceFactor(node* temp)
    {
        if (temp == NULL)
        {
            return 0;
        }

        return getHeight(temp->left) -
               getHeight(temp->right);
    }

    // Left Rotation (Anticlockwise)
    node* leftRotate(node* x)
    {
        node* y = x->right;
        node* T2 = y->left;

        y->left = x;
        x->right = T2;

        // Update heights
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));

        return y;
    }

    // Right Rotation (Clockwise)
    node* rightRotate(node* y)
    {
        node* x = y->left;
        node* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));

        return x;
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