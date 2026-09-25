// In question 1, define a method to search a node with the give item.

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
        // If list is empty
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
};

int main()
{
    CDLL list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);

    if (list.search(30))
    {
        cout << "Item found." << endl;
    }
    else
    {
        cout << "Item not found." << endl;
    }

    return 0;
}