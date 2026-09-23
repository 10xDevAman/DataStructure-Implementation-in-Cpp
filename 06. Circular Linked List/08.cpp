// In question 1, define a method to delete last node of the list.


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
    CLL()
    {
        last = nullptr;
    }

    void insertAtBeginning(int value)
    {
        Node *newNode = new Node;

        newNode->data = value;

        if (last == nullptr)
        {
            newNode->next = newNode;
            last = newNode;
            return;
        }

        newNode->next = last->next;
        last->next = newNode;
    }

    void insertAtEnd(int value)
    {
        Node *newNode = new Node;

        newNode->data = value;

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

    void insertAfter(Node *node, int value)
    {
        if (node == nullptr)
            return;

        Node *newNode = new Node;

        newNode->data = value;
        newNode->next = node->next;
        node->next = newNode;

        if (node == last)
            last = newNode;
    }

    void deleteFirst()
    {
        if (last == nullptr)
            return;

        Node *first = last->next;

        if (first == last)
        {
            delete first;
            last = nullptr;
            return;
        }

        last->next = first->next;

        delete first;
    }

    void deleteLast()
    {
        // Empty list
        if (last == nullptr)
            return;

        // Only one node
        if (last->next == last)
        {
            delete last;
            last = nullptr;
            return;
        }

        // Find node before last
        Node *temp = last->next;

        while (temp->next != last)
        {
            temp = temp->next;
        }

        // Remove last node
        temp->next = last->next;

        delete last;

        // Previous node becomes last
        last = temp;
    }
};