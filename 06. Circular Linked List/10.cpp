// In question 1, define a destructor to deallocates memory for all the nodes in the linked list.


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

    // Q3: Insert at beginning
    void insertAtBeginning(int value)
    {
        Node *newNode = new Node;

        newNode->data = value;

        // Empty list
        if (last == nullptr)
        {
            newNode->next = newNode;
            last = newNode;
            return;
        }

        newNode->next = last->next;
        last->next = newNode;
    }

    // Q4: Insert at end
    void insertAtEnd(int value)
    {
        Node *newNode = new Node;

        newNode->data = value;

        // Empty list
        if (last == nullptr)
        {
            newNode->next = newNode;
            last = newNode;
            return;
        }

        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }

    // Q5: Search an item
    int search(int item)
    {
        if (last == nullptr)
            return -1;

        Node *first = last->next;
        Node *temp = first;

        int index = 0;

        do
        {
            if (temp->data == item)
                return index;

            temp = temp->next;
            index++;

        } while (temp != first);

        return -1;
    }

    // Q6: Insert after specified node
    void insertAfter(Node *node, int value)
    {
        if (node == nullptr)
            return;

        Node *newNode = new Node;

        newNode->data = value;
        newNode->next = node->next;

        node->next = newNode;

        // If node is last, new node becomes last
        if (node == last)
            last = newNode;
    }

    // Q7: Delete first node
    void deleteFirst()
    {
        if (last == nullptr)
            return;

        Node *first = last->next;

        // Only one node
        if (first == last)
        {
            delete first;
            last = nullptr;
            return;
        }

        last->next = first->next;

        delete first;
    }

    // Q8: Delete last node
    void deleteLast()
    {
        if (last == nullptr)
            return;

        // Only one node
        if (last->next == last)
        {
            delete last;
            last = nullptr;
            return;
        }

        Node *temp = last->next;

        // Find node before last
        while (temp->next != last)
        {
            temp = temp->next;
        }

        temp->next = last->next;

        delete last;

        last = temp;
    }

    // Q9: Delete specific node
    void deleteNode(int item)
    {
        if (last == nullptr)
            return;

        Node *first = last->next;
        Node *previous = last;
        Node *current = first;

        do
        {
            if (current->data == item)
            {
                // Only one node
                if (current == last && current == first)
                {
                    delete current;
                    last = nullptr;
                    return;
                }

                // Delete first node
                if (current == first)
                {
                    last->next = current->next;
                    delete current;
                    return;
                }

                // Delete last node
                if (current == last)
                {
                    previous->next = current->next;
                    delete current;
                    last = previous;
                    return;
                }

                // Delete middle node
                previous->next = current->next;
                delete current;
                return;
            }

            previous = current;
            current = current->next;

        } while (current != first);
    }

    ~CLL()
    {
        if (last == nullptr)
            return;

        Node *first = last->next;
        Node *temp = first;

        while (temp != last)
        {
            Node *nextNode = temp->next;

            delete temp;

            temp = nextNode;
        }

        delete last;

        last = nullptr;
    }
};


int main()
{
    CLL list;

    // Insert at beginning
    list.insertAtBeginning(20);
    list.insertAtBeginning(10);

    // Insert at end
    list.insertAtEnd(30);
    list.insertAtEnd(40);

    /*
        List:

        10 → 20 → 30 → 40
        ↑              ↓
        └──────────────┘
    */

    // Search
    int result = list.search(30);

    if (result != -1)
        cout << "Item found at index: " << result << endl;
    else
        cout << "Item not found" << endl;

    // Delete first
    list.deleteFirst();

    // Delete last
    list.deleteLast();

    // Delete specific node
    list.deleteNode(20);

    return 0;
}