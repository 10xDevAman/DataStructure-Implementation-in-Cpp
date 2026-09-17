// In question 1, define a method to insert a data into the list at the end


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

        // If list is empty
        if (start == NULL)
        {
            start = newNode;
            return;
        }

        // Traverse to the last node
        Node *temp = start;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        // Connect last node to new node
        temp->next = newNode;
    }
};

int main()
{
    SLL list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);

    return 0;
}