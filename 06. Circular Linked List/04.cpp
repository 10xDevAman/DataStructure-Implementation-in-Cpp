// In question 1, define a method to insert a data into the list at the end

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

        // Empty list
        if (last == nullptr)
        {
            newNode->next = newNode;
            last = newNode;
            return;
        }

        // New node will point to first node
        newNode->next = last->next;

        // Current last points to new node
        last->next = newNode;

        // New node becomes last
        last = newNode;
    }
};