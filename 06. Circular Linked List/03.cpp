// In question 1, define a method to insert a data into the list at the beginning.


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
        last = NULL;
    }

    void insertAtBeginning(int value)
    {
        Node *newNode = new Node;

        newNode->data = value;

        // Empty list
        if (last == NULL)
        {
            newNode->next = newNode;
            last = newNode;
            return;
        }

        // Insert before first node
        newNode->next = last->next;
        last->next = newNode;
    }
};