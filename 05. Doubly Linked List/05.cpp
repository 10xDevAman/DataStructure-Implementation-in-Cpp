// In question 1, define a method to search a node with the give item.


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

        // If list is empty
        if (start == NULL)
        {
            newNode->prev = NULL;
            start = newNode;
            return;
        }

        // Traverse to last node
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
            {
                return index;
            }

            temp = temp->next;
            index++;
        }

        return -1;
    }
};

int main()
{
    DLL list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);

    cout << "Index: " << list.search(30);

    return 0;
}