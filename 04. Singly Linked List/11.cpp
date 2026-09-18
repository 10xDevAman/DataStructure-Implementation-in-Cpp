// In question 1, define a copy constructor to implement deep copy.


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

    // Copy Constructor - Deep Copy
    SLL(const SLL &obj)
    {
        start = NULL;

        // If original list is empty
        if (obj.start == NULL)
            return;

        // Copy first node
        Node *source = obj.start;

        start = new Node;
        start->data = source->data;
        start->next = NULL;

        // Copy remaining nodes
        Node *destination = start;
        source = source->next;

        while (source != NULL)
        {
            Node *newNode = new Node;

            newNode->data = source->data;
            newNode->next = NULL;

            destination->next = newNode;
            destination = newNode;

            source = source->next;
        }
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
        if (start == NULL)
            return;

        if (start->data == item)
        {
            deleteFirst();
            return;
        }

        Node *temp = start;

        while (temp->next != NULL &&
               temp->next->data != item)
        {
            temp = temp->next;
        }

        if (temp->next == NULL)
            return;

        Node *nodeToDelete = temp->next;

        temp->next = nodeToDelete->next;

        delete nodeToDelete;
    }

    // Destructor
    ~SLL()
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
    SLL list1;

    list1.insertAtEnd(10);
    list1.insertAtEnd(20);
    list1.insertAtEnd(30);

    // Copy Constructor
    SLL list2 = list1;

    return 0;
}