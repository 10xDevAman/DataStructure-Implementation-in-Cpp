// In question 1, define a method to delete a specific node.

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

    // Delete the first node
    bool deleteFirst()
    {
        if (start == NULL)
        {
            return false;
        }

        if (start->next == start)
        {
            delete start;
            start = NULL;
            return true;
        }

        node* temp = start;
        node* last = start->prev;

        start = start->next;

        start->prev = last;
        last->next = start;

        delete temp;

        return true;
    }

    // Delete the last node
    bool deleteLast()
    {
        if (start == NULL)
        {
            return false;
        }

        if (start->next == start)
        {
            delete start;
            start = NULL;
            return true;
        }

        node* last = start->prev;
        node* secondLast = last->prev;

        secondLast->next = start;
        start->prev = secondLast;

        delete last;

        return true;
    }

    // Delete a specific node
    bool deleteNode(int item)
    {
        // If list is empty
        if (start == NULL)
        {
            return false;
        }

        node* temp = start;

        do
        {
            // Check whether current node contains the item
            if (temp->data == item)
            {
                // Case 1: Only one node exists
                if (temp->next == temp)
                {
                    delete temp;
                    start = NULL;
                    return true;
                }

                // Case 2: Delete first node
                if (temp == start)
                {
                    node* last = start->prev;

                    start = start->next;

                    start->prev = last;
                    last->next = start;

                    delete temp;
                    return true;
                }

                // Case 3: Delete any other node
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;

                delete temp;
                return true;
            }

            temp = temp->next;

        } while (temp != start);

        // Item not found
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

    if (list.deleteNode(30))
    {
        cout << "Node deleted successfully." << endl;
    }
    else
    {
        cout << "Node not found." << endl;
    }

    return 0;
}