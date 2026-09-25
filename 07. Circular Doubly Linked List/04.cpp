// In question 1, define a method to insert a data into the list at the end

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

        // If list is empty
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
        // Create a new node
        node* n = new node;

        n->data = data;

        // If list is empty
        if (start == NULL)
        {
            n->next = n;
            n->prev = n;

            start = n;
        }
        else
        {
            // Get the last node
            node* last = start->prev;

            // Connect new node
            n->next = start;
            n->prev = last;

            // Update last node
            last->next = n;

            // Update first node
            start->prev = n;
        }
    }
};

int main()
{
    CDLL list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);

    return 0;
}