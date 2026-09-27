// In question 1, define a copy assignment operator to implement deep copy.

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

    // Copy Constructor - Deep Copy
    CDLL(const CDLL& other)
    {
        start = NULL;

        if (other.start == NULL)
        {
            return;
        }

        node* current = other.start;

        do
        {
            insertAtEnd(current->data);

            current = current->next;

        } while (current != other.start);
    }

    // Insert data at the end
    void insertAtEnd(int data)
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
        }
    }

    // Copy Assignment Operator - Deep Copy
    CDLL& operator=(const CDLL& other)
    {
        // Self-assignment check
        if (this == &other)
        {
            return *this;
        }

        // Delete existing nodes
        if (start != NULL)
        {
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

        // Copy nodes from other list
        if (other.start != NULL)
        {
            node* current = other.start;

            do
            {
                insertAtEnd(current->data);

                current = current->next;

            } while (current != other.start);
        }

        // Return current object
        return *this;
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
    CDLL list1;

    list1.insertAtEnd(10);
    list1.insertAtEnd(20);
    list1.insertAtEnd(30);

    CDLL list2;

    // Copy assignment operator
    list2 = list1;

    return 0;
}