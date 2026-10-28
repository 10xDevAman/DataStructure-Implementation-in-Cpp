// In question 1, define a method for preorder traversing of BST 

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

    // Recursive preorder traversal
    void preorder(node* temp)
    {
        if (temp == NULL)
        {
            return;
        }

        cout << temp->data << " ";  // Root
        preorder(temp->left);       // Left
        preorder(temp->right);      // Right
    }

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

        if (root == NULL)
        {
            root = n;
            return;
        }

        node* temp = root;
        node* parent = NULL;

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

        if (data < parent->data)
        {
            parent->left = n;
        }
        else
        {
            parent->right = n;
        }
    }

    // Preorder traversal
    void preorder()
    {
        if (isEmpty())
        {
            cout << "Tree is empty." << endl;
            return;
        }

        preorder(root);
        cout << endl;
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

    cout << "Preorder Traversal: ";
    tree.preorder();

    return 0;
}