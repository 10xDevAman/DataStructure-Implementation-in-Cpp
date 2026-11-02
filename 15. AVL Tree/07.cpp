// In question 1, define a method to delete an element from the tree. 

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

    // Left Rotation
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

    // Right Rotation
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

    // Insert a new element
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

    // Delete an element
    node* deleteNode(node* temp, int data)
    {
        // Normal BST deletion
        if (temp == NULL)
            return temp;

        if (data < temp->data)
            temp->left = deleteNode(temp->left, data);

        else if (data > temp->data)
            temp->right = deleteNode(temp->right, data);

        else
        {
            // Case 1 and Case 2: Zero or one child
            if (temp->left == NULL || temp->right == NULL)
            {
                node* child = (temp->left != NULL)
                              ? temp->left
                              : temp->right;

                // No child
                if (child == NULL)
                {
                    delete temp;
                    return NULL;
                }

                // One child
                node* oldNode = temp;
                temp = child;
                delete oldNode;
            }
            else
            {
                // Case 3: Two children
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
        {
            return rightRotate(temp);
        }

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
        {
            return leftRotate(temp);
        }

        // RL Case
        if (balance < -1 &&
            getBalanceFactor(temp->right) > 0)
        {
            temp->right = rightRotate(temp->right);
            return leftRotate(temp);
        }

        return temp;
    }

public:
    // Constructor
    AVL()
    {
        root = NULL;
    }

    // Public insertion method
    void insert(int data)
    {
        root = insertNode(root, data);
    }

    // Public deletion method
    void remove(int data)
    {
        root = deleteNode(root, data);
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

    // Delete an element
    tree.remove(40);

    return 0;
}