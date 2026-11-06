// In question 1, define a search method to find the element in the tree.

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

    // Get height
    int getHeight(node* temp)
    {
        if (temp == NULL)
            return 0;

        return temp->height;
    }

    // Get balance factor
    int getBalanceFactor(node* temp)
    {
        if (temp == NULL)
            return 0;

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

        x->height = 1 + max(
            getHeight(x->left),
            getHeight(x->right)
        );

        y->height = 1 + max(
            getHeight(y->left),
            getHeight(y->right)
        );

        return y;
    }

    // Right Rotation (Clockwise)
    node* rightRotate(node* y)
    {
        node* x = y->left;
        node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = 1 + max(
            getHeight(y->left),
            getHeight(y->right)
        );

        x->height = 1 + max(
            getHeight(x->left),
            getHeight(x->right)
        );

        return x;
    }

    // Insert element
    node* insertNode(node* temp, int data)
    {
        if (temp == NULL)
        {
            node* newNode = new node;

            newNode->data = data;
            newNode->height = 1;
            newNode->left = NULL;
            newNode->right = NULL;

            return newNode;
        }

        if (data < temp->data)
            temp->left = insertNode(temp->left, data);

        else if (data > temp->data)
            temp->right = insertNode(temp->right, data);

        else
            return temp;

        // Update height
        temp->height = 1 + max(
            getHeight(temp->left),
            getHeight(temp->right)
        );

        int balance = getBalanceFactor(temp);

        // LL Case
        if (balance > 1 && data < temp->left->data)
            return rightRotate(temp);

        // RR Case
        if (balance < -1 && data > temp->right->data)
            return leftRotate(temp);

        // LR Case
        if (balance > 1 && data > temp->left->data)
        {
            temp->left = leftRotate(temp->left);
            return rightRotate(temp);
        }

        // RL Case
        if (balance < -1 && data < temp->right->data)
        {
            temp->right = rightRotate(temp->right);
            return leftRotate(temp);
        }

        return temp;
    }

    // Find minimum value node
    node* minValueNode(node* temp)
    {
        node* current = temp;

        while (current->left != NULL)
            current = current->left;

        return current;
    }

    // Delete element
    node* deleteNode(node* temp, int data)
    {
        if (temp == NULL)
            return temp;

        if (data < temp->data)
            temp->left = deleteNode(temp->left, data);

        else if (data > temp->data)
            temp->right = deleteNode(temp->right, data);

        else
        {
            // Zero or one child
            if (temp->left == NULL || temp->right == NULL)
            {
                node* child = (temp->left != NULL)
                              ? temp->left
                              : temp->right;

                if (child == NULL)
                {
                    delete temp;
                    return NULL;
                }

                node* oldNode = temp;
                temp = child;
                delete oldNode;
            }
            else
            {
                // Two children
                node* successor = minValueNode(temp->right);

                temp->data = successor->data;

                temp->right = deleteNode(
                    temp->right,
                    successor->data
                );
            }
        }

        if (temp == NULL)
            return temp;

        // Update height
        temp->height = 1 + max(
            getHeight(temp->left),
            getHeight(temp->right)
        );

        int balance = getBalanceFactor(temp);

        // LL Case
        if (balance > 1 &&
            getBalanceFactor(temp->left) >= 0)
            return rightRotate(temp);

        // LR Case
        if (balance > 1 &&
            getBalanceFactor(temp->left) < 0)
        {
            temp->left = leftRotate(temp->left);
            return rightRotate(temp);
        }

        // RR Case
        if (balance < -1 &&
            getBalanceFactor(temp->right) <= 0)
            return leftRotate(temp);

        // RL Case
        if (balance < -1 &&
            getBalanceFactor(temp->right) > 0)
        {
            temp->right = rightRotate(temp->right);
            return leftRotate(temp);
        }

        return temp;
    }

    // Preorder Traversal
    void preorder(node* temp)
    {
        if (temp == NULL)
            return;

        cout << temp->data << " ";

        preorder(temp->left);
        preorder(temp->right);
    }

    // Postorder Traversal
    void postorder(node* temp)
    {
        if (temp == NULL)
            return;

        postorder(temp->left);
        postorder(temp->right);

        cout << temp->data << " ";
    }

    // Inorder Traversal
    void inorder(node* temp)
    {
        if (temp == NULL)
            return;

        inorder(temp->left);

        cout << temp->data << " ";

        inorder(temp->right);
    }

    // Destroy AVL Tree
    void destroyTree(node* temp)
    {
        if (temp == NULL)
            return;

        destroyTree(temp->left);
        destroyTree(temp->right);

        delete temp;
    }

    // Search for an element
    bool searchNode(node* temp, int data)
    {
        if (temp == NULL)
            return false;

        if (temp->data == data)
            return true;

        if (data < temp->data)
            return searchNode(temp->left, data);

        return searchNode(temp->right, data);
    }

public:
    // Constructor
    AVL()
    {
        root = NULL;
    }

    // Insert method
    void insert(int data)
    {
        root = insertNode(root, data);
    }

    // Delete method
    void remove(int data)
    {
        root = deleteNode(root, data);
    }

    // Preorder method
    void preorder()
    {
        preorder(root);
        cout << endl;
    }

    // Postorder method
    void postorder()
    {
        postorder(root);
        cout << endl;
    }

    // Inorder method
    void inorder()
    {
        inorder(root);
        cout << endl;
    }

    // Search method
    bool search(int data)
    {
        return searchNode(root, data);
    }

    // Destructor
    ~AVL()
    {
        destroyTree(root);
        root = NULL;
    }
};

int main()
{
    AVL tree;

    // Insert elements
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);

    // Traversals
    cout << "Preorder: ";
    tree.preorder();

    cout << "Inorder: ";
    tree.inorder();

    cout << "Postorder: ";
    tree.postorder();

    // Search
    int key = 30;

    if (tree.search(key))
        cout << key << " found in AVL Tree." << endl;
    else
        cout << key << " not found in AVL Tree." << endl;

    // Delete
    tree.remove(40);

    cout << "After deletion: ";
    tree.inorder();

    return 0;
}