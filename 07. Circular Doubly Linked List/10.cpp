// In question 1, define a destructor to deallocates memory for all the nodes in the linked list.

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

    // Destructor
    ~CDLL()
    {
        if (start == NULL)
        {
            return;
        }

        node* current = start->next;

        while (current != start)
        {
            node* temp = current;
            current = current->next;

            delete temp;
        }

        delete start;

        start = NULL;
    }
};

int main()
{
    CDLL list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);

    return 0;
}