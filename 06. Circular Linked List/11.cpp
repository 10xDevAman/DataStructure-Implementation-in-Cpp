// In question 1, define a copy constructor to implement deep copy.


#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class CLL
{
private:
    Node *last;

public:

    // Q2: Constructor
    CLL()
    {
        last = nullptr;
    }

    // Q11: Copy Constructor - Deep Copy
    CLL(const CLL &obj)
    {
        last = nullptr;

        // Source list is empty
        if (obj.last == nullptr)
            return;

        Node *sourceFirst = obj.last->next;
        Node *source = sourceFirst;

        // Create first node
        Node *newNode = new Node;

        newNode->data = source->data;
        newNode->next = nullptr;

        Node *newFirst = newNode;
        Node *newLast = newNode;

        source = source->next;

        // Copy remaining nodes
        while (source != sourceFirst)
        {
            newNode = new Node;

            newNode->data = source->data;
            newNode->next = nullptr;

            newLast->next = newNode;
            newLast = newNode;

            source = source->next;
        }

        // Make the new list circular
        newLast->next = newFirst;

        // Update last pointer
        last = newLast;
    }
};