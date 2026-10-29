// In question 1, define a method to delete an element from BST 

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
            // Case 1: No left child
            if (temp->left == NULL)
            {
                node* child = temp->right;
                delete temp;
                return child;
            }

            // Case 2: No right child
            if (temp->right == NULL)
            {
                node* child = temp->left;
                delete temp;
                return child;
            }

            // Case 3: Two children
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

    cout << "Before deletion: ";
    tree.inorder();

    tree.deleteElement(20);

    cout << "After deleting 20: ";
    tree.inorder();

    tree.deleteElement(30);

    cout << "After deleting 30: ";
    tree.inorder();

    tree.deleteElement(50);

    cout << "After deleting 50: ";
    tree.inorder();

    return 0;
}