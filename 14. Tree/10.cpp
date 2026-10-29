// In question 1, define a destructor to release memory of all the nodes of BST. 

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

    // Delete all nodes recursively
    void destroyTree(node* temp)
    {
        if (temp == NULL)
        {
            return;
        }

        destroyTree(temp->left);
        destroyTree(temp->right);

        delete temp;
    }

    // Helper method for deletion
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

    // Check if tree is empty
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

    // Postorder traversal
    void postorder(node* temp)
    {
        if (temp == NULL)
        {
            return;
        }

        postorder(temp->left);
        postorder(temp->right);
        cout << temp->data << " ";
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

    // Destructor
    ~BST()
    {
        destroyTree(root);
        root = NULL;
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

    cout << "Inorder Traversal: ";
    tree.inorder();

    if (tree.search(40))
    {
        cout << "40 found in BST." << endl;
    }

    tree.deleteElement(30);

    cout << "After deletion: ";
    tree.inorder();

    return 0;
}