// In question 1, define a destructor to deallocates memory for all the nodes in the linked list.


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
        if (start == NULL)
            return;

        if (start->next == NULL)
        {
            delete start;
            start = NULL;
            return;
        }

        Node *temp = start;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        Node *previous = temp->prev;

        delete temp;

        previous->next = NULL;
    }

    // Delete specific node
    void deleteNode(int item)
    {
        if (start == NULL)
            return;

        Node *temp = start;

        while (temp != NULL && temp->data != item)
        {
            temp = temp->next;
        }

        if (temp == NULL)
            return;

        if (temp == start)
        {
            deleteFirst();
            return;
        }

        if (temp->next == NULL)
        {
            deleteLast();
            return;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        delete temp;
    }

    // Destructor
    ~DLL()
    {
        Node *temp;

        while (start != NULL)
        {
            temp = start;
            start = start->next;

            delete temp;
        }
    }
};

int main()
{
    DLL list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);

    return 0;
}