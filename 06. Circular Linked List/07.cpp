// In question 1, define a method to delete first node from the list.


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
        // Empty list
        if (last == nullptr)
            return;

        Node *first = last->next;

        // Only one node
        if (first == last)
        {
            delete first;
            last = nullptr;
            return;
        }

        // More than one node
        last->next = first->next;

        delete first;
    }
};