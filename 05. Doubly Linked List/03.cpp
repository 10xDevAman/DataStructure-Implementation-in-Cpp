// In question 1, define a method to insert a data into the list at the beginning.


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

        // If list is not empty
        if (start != NULL)
        {
            start->prev = newNode;
        }

        start = newNode;
    }
};

int main()
{
    DLL list;

    list.insertAtBeginning(30);
    list.insertAtBeginning(20);
    list.insertAtBeginning(10);

    return 0;
}