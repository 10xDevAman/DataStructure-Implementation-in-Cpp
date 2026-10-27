// In question 1, define a method to insert a new element in the BST

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

    // Insert a new element
    void insert(int data)
    {
        node* n = new node;

        n->data = data;
        n->left = NULL;
        n->right = NULL;

        // If tree is empty
        if (root == NULL)
        {
            root = n;
            return;
        }

        node* temp = root;
        node* parent = NULL;

        // Find the correct position
        while (temp != NULL)
        {
            parent = temp;

            if (data < temp->data)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }

        // Insert the new node
        if (data < parent->data)
        {
            parent->left = n;
        }
        else
        {
            parent->right = n;
        }
    }
};

int main()
{
    BST tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);

    return 0;
}