// In question 1, define a method to insert a data into the list after the specified node of the list.


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

        // New node points to node's next
        newNode->next = node->next;

        // Node points to new node
        node->next = newNode;

        // If node was last, new node becomes last
        if (node == last)
            last = newNode;
    }
};