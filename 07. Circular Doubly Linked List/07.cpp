// In question 1, define a method to delete first node from the list.

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

    // Delete first node
    bool deleteFirst()
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

        // Store first and last nodes
        node* temp = start;
        node* last = start->prev;

        // Move start to the second node
        start = start->next;

        // Update circular links
        start->prev = last;
        last->next = start;

        // Delete old first node
        delete temp;

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

    if (list.deleteFirst())
    {
        cout << "First node deleted successfully." << endl;
    }
    else
    {
        cout << "List is empty." << endl;
    }

    return 0;
}