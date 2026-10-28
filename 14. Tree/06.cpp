// In question 1, define a method for inorder traversing of BST 

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

    // Recursive inorder traversal
    void inorder(node* temp)
    {
        if (temp == NULL)
        {
            return;
        }

        inorder(temp->left);        // Left
        cout << temp->data << " ";  // Root
        inorder(temp->right);       // Right
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
    void preorder(node* temp)
    {
        if (temp == NULL)
        {
            return;
        }

        cout << temp->data << " ";
        preorder(temp->left);
        preorder(temp->right);
    }

    // Public inorder traversal
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

    cout << "Inorder Traversal: ";
    tree.inorder();

    return 0;
}