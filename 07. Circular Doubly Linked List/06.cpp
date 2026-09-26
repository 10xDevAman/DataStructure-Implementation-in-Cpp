// In question 1, define a method to insert a data into the list after the specified node of the list.

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

    // Search a node with the given item
    bool search(int item)
    {
        if (start == NULL)
        {
            return false;
        }

        node* temp = start;

        do
        {
            if (temp->data == item)
            {
                return true;
            }

            temp = temp->next;

        } while (temp != start);

        return false;
    }

    // Insert data after the specified node
    bool insertAfter(int item, int data)
    {
        // If list is empty
        if (start == NULL)
        {
            return false;
        }

        node* temp = start;

        do
        {
            // Find the specified node
            if (temp->data == item)
            {
                node* n = new node;

                n->data = data;

                // Connect new node
                n->prev = temp;
                n->next = temp->next;

                // Update next node's previous pointer
                temp->next->prev = n;

                // Update specified node's next pointer
                temp->next = n;

                return true;
            }

            temp = temp->next;

        } while (temp != start);

        // Specified node not found
        return false;
    }
};

int main()
{
    CDLL list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);

    // Insert 25 after 20
    if (list.insertAfter(20, 25))
    {
        cout << "Data inserted successfully." << endl;
    }
    else
    {
        cout << "Specified node not found." << endl;
    }

    return 0;
}