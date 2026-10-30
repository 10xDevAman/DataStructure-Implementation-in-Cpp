// In question 1, define a copy constructor to implement deep copy.

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

    // Copy tree recursively
    node* copyTree(node* temp)
    {
        if (temp == NULL)
        {
            return NULL;
        }

        node* n = new node;

        n->data = temp->data;
        n->left = copyTree(temp->left);
        n->right = copyTree(temp->right);

        return n;
    }

    // Destroy tree recursively
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

            // Two children
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

public:
    // Constructor
    BST()
    {
        root = NULL;
    }

    // Copy constructor
    BST(const BST& other)
    {
        root = copyTree(other.root);
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

    // Preorder traversal helper
    void preorderTraversal(node* temp)
    {
        if (temp == NULL)
        {
            return;
        }

        cout << temp->data << " ";
        preorderTraversal(temp->left);
        preorderTraversal(temp->right);
    }

    // Public preorder method
    void preorder()
    {
        preorderTraversal(root);
        cout << endl;
    }

    // Public inorder method
    void inorder()
    {
        inorder(root);
        cout << endl;
    }

    // Postorder traversal helper
    void postorderTraversal(node* temp)
    {
        if (temp == NULL)
        {
            return;
        }

        postorderTraversal(temp->left);
        postorderTraversal(temp->right);
        cout << temp->data << " ";
    }

    // Public postorder method
    void postorder()
    {
        postorderTraversal(root);
        cout << endl;
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
    BST tree1;

    tree1.insert(50);
    tree1.insert(30);
    tree1.insert(70);
    tree1.insert(20);
    tree1.insert(40);
    tree1.insert(60);
    tree1.insert(80);

    // Copy constructor called
    BST tree2 = tree1;

    cout << "Inorder of tree1: ";
    tree1.inorder();

    cout << "Inorder of tree2: ";
    tree2.inorder();

    // Delete an element from copied tree
    tree2.deleteElement(30);

    cout << "tree2 after deletion: ";
    tree2.inorder();

    cout << "tree1 after deletion in tree2: ";
    tree1.inorder();

    return 0;
}