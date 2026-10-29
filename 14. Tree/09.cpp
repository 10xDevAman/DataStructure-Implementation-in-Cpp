// In question 1, define a method to search an item in the BST

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

    // Recursive deletion helper
    node* deleteNode(node* temp, int data)
    {
        if (temp == NULL)
        {
            return NULL;
        }

        if (data < temp->data)
        {
            temp->left = deleteNode(temp->left, data);
        }
        else if (data > temp->data)
        {
            temp->right = deleteNode(temp->right, data);
        }
        else
        {
            // No left child
            if (temp->left == NULL)
            {
                node* child = temp->right;
                delete temp;
                return child;
            }

            // No right child
            if (temp->right == NULL)
            {
                node* child = temp->left;
                delete temp;
                return child;
            }

            // Two children: find inorder successor
            node* successor = temp->right;

            while (successor->left != NULL)
            {
                successor = successor->left;
            }

            temp->data = successor->data;

            temp->right = deleteNode(
                temp->right,
                successor->data
            );
        }

        return temp;
    }

    // Inorder traversal helper
    void inorder(node* temp)
    {
        if (temp == NULL)
        {
            return;
        }

        inorder(temp->left);
        cout << temp->data << " ";
        inorder(temp->right);
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

    // Delete an element
    void deleteElement(int data)
    {
        root = deleteNode(root, data);
    }

    // Search an item
    bool search(int data)
    {
        node* temp = root;

        while (temp != NULL)
        {
            if (data == temp->data)
            {
                return true;
            }
            else if (data < temp->data)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }

        return false;
    }

    // Inorder traversal
    void inorder()
    {
        if (isEmpty())
        {
            cout << "Tree is empty." << endl;
            return;
        }

        inorder(root);
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
    tree.insert(60);
    tree.insert(80);

    int item = 40;

    if (tree.search(item))
    {
        cout << item << " found in BST." << endl;
    }
    else
    {
        cout << item << " not found in BST." << endl;
    }

    item = 100;

    if (tree.search(item))
    {
        cout << item << " found in BST." << endl;
    }
    else
    {
        cout << item << " not found in BST." << endl;
    }

    return 0;
}