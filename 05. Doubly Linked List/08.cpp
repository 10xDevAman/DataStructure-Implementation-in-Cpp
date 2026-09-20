// In question 1, define a method to delete last node of the list.


#include <iostream>
using namespace std;

// Node
class Node
{
public:
    Node *prev;
    int data;
    Node *next;
};

// Doubly Linked List
class DLL
{
private:
    Node *start;

public:
    // Constructor
    DLL()
    {
        start = NULL;
    }

    // Insert data at beginning
    void insertAtBeginning(int value)
    {
        Node *newNode = new Node;

        newNode->prev = NULL;
        newNode->data = value;
        newNode->next = start;

        if (start != NULL)
        {
            start->prev = newNode;
        }

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
            newNode->prev = NULL;
            start = newNode;
            return;
        }

        Node *temp = start;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        newNode->prev = temp;
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
        newNode->prev = node;
        newNode->next = node->next;

        if (node->next != NULL)
        {
            node->next->prev = newNode;
        }

        node->next = newNode;
    }

    // Delete first node
    void deleteFirst()
    {
        if (start == NULL)
            return;

        Node *temp = start;

        start = start->next;

        if (start != NULL)
        {
            start->prev = NULL;
        }

        delete temp;
    }

    // Delete last node
    void deleteLast()
    {
        // Case 1: Empty list
        if (start == NULL)
            return;

        // Case 2: Only one node
        if (start->next == NULL)
        {
            delete start;
            start = NULL;
            return;
        }

        // Find last node
        Node *temp = start;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        // Move to previous node
        Node *previous = temp->prev;

        // Delete last node
        delete temp;

        // Make previous node the last node
        previous->next = NULL;
    }
};

int main()
{
    DLL list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);

    list.deleteLast();

    return 0;
}