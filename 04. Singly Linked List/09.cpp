// In question 1, define a method to delete a specific node.


#include <iostream>
using namespace std;

// Node
class Node
{
public:
    int data;
    Node *next;
};

// Singly Linked List
class SLL
{
private:
    Node *start;

public:
    // Constructor
    SLL()
    {
        start = NULL;
    }

    // Insert data at beginning
    void insertAtBeginning(int value)
    {
        Node *newNode = new Node;

        newNode->data = value;
        newNode->next = start;

        start = newNode;
    }

    // Insert data at end
    void insertAtEnd(int value)
    {
        Node *newNode = new Node;

        newNode->data = value;
        newNode->next = NULL;

        if (start == NULL)
        {
            start = newNode;
            return;
        }

        Node *temp = start;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    // Search an item
    int search(int item)
    {
        Node *temp = start;
        int index = 0;

        while (temp != NULL)
        {
            if (temp->data == item)
                return index;

            temp = temp->next;
            index++;
        }

        return -1;
    }

    // Insert data after specified node
    void insertAfter(Node *node, int value)
    {
        if (node == NULL)
            return;

        Node *newNode = new Node;

        newNode->data = value;
        newNode->next = node->next;

        node->next = newNode;
    }

    // Delete first node
    void deleteFirst()
    {
        if (start == NULL)
            return;

        Node *temp = start;

        start = start->next;

        delete temp;
    }

    // Delete last node
    void deleteLast()
    {
        if (start == NULL)
            return;

        if (start->next == NULL)
        {
            delete start;
            start = NULL;
            return;
        }

        Node *temp = start;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    // Delete specific node
    void deleteNode(int item)
    {
        // Case 1: Empty list
        if (start == NULL)
            return;

        // Case 2: First node contains the item
        if (start->data == item)
        {
            deleteFirst();
            return;
        }

        // Find previous node
        Node *temp = start;

        while (temp->next != NULL &&
               temp->next->data != item)
        {
            temp = temp->next;
        }

        // Item not found
        if (temp->next == NULL)
            return;

        // Node to be deleted
        Node *nodeToDelete = temp->next;

        // Connect previous node to next node
        temp->next = nodeToDelete->next;

        // Delete node
        delete nodeToDelete;
    }
};

int main()
{
    SLL list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);

    list.deleteNode(30);

    return 0;
}