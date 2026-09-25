// In question 1, define a method to insert a data into the list at the beginning.

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

            // Connect new node with first and last node
            n->next = start;
            n->prev = last;

            // Update last node
            last->next = n;

            // Update first node
            start->prev = n;

            // Make new node the first node
            start = n;
        }
    }
};

int main()
{
    CDLL list;

    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.insertAtBeginning(30);

    return 0;
}