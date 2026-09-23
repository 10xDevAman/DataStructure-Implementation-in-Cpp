// In question 1, define a method to search a node with the give item.


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
};