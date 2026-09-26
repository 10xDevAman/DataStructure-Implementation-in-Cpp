// In question 1, define a method to delete last node of the list.

#include <iostream>
using namespace std;

class CDLL
{
private:
    struct node
    {
        int data;
        node* prev;
        node* next;
    };

    node* start;

public:
    // Constructor
    CDLL()
    {
        start = NULL;
    }

    // Insert data at the beginning
    void insertAtBeginning(int data)
    {
        node* n = new node;
        n->data = data;

        if (start == NULL)
        {
            n->next = n;
            n->prev = n;
            start = n;
        }
        else
        {
            node* last = start->prev;

            n->next = start;
            n->prev = last;

            last->next = n;
            start->prev = n;

            start = n;
        }
    }

    // Insert data at the end
    void insertAtEnd(int data)
    {
        node* n = new node;
        n->data = data;

        if (start == NULL)
        {
            n->next = n;
            n->prev = n;
            start = n;
        }
        else
        {
            node* last = start->prev;

            n->next = start;
            n->prev = last;

            last->next = n;
            start->prev = n;
        }
    }

    // Delete the last node
    bool deleteLast()
    {
        // If list is empty
        if (start == NULL)
        {
            return false;
        }

        // If only one node exists
        if (start->next == start)
        {
            delete start;
            start = NULL;

            return true;
        }

        // Get the last node
        node* last = start->prev;

        // Get the second-last node
        node* secondLast = last->prev;

        // Connect second-last node with first node
        secondLast->next = start;
        start->prev = secondLast;

        // Delete old last node
        delete last;

        return true;
    }
};

int main()
{
    CDLL list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);

    if (list.deleteLast())
    {
        cout << "Last node deleted successfully." << endl;
    }
    else
    {
        cout << "List is empty." << endl;
    }

    return 0;
}