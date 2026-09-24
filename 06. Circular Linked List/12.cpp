// In question 1, define a copy assignment operator to implement deep copy.



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

    // Q2: Constructor
    CLL()
    {
        last = nullptr;
    }

    // Q11: Copy Constructor
    CLL(const CLL &obj)
    {
        last = nullptr;

        if (obj.last == nullptr)
            return;

        Node *sourceFirst = obj.last->next;
        Node *source = sourceFirst;

        Node *newNode = new Node;

        newNode->data = source->data;
        newNode->next = nullptr;

        Node *newFirst = newNode;
        Node *newLast = newNode;

        source = source->next;

        while (source != sourceFirst)
        {
            newNode = new Node;

            newNode->data = source->data;
            newNode->next = nullptr;

            newLast->next = newNode;
            newLast = newNode;

            source = source->next;
        }

        newLast->next = newFirst;
        last = newLast;
    }

    // Q12: Copy Assignment Operator
    CLL& operator=(const CLL &obj)
    {
        // Self-assignment check
        if (this == &obj)
            return *this;

        // Delete existing nodes
        if (last != nullptr)
        {
            Node *first = last->next;
            Node *temp = first;

            while (temp != last)
            {
                Node *nextNode = temp->next;

                delete temp;

                temp = nextNode;
            }

            delete last;
            last = nullptr;
        }

        // Source list is empty
        if (obj.last == nullptr)
            return *this;

        // Copy first node
        Node *sourceFirst = obj.last->next;
        Node *source = sourceFirst;

        Node *newNode = new Node;

        newNode->data = source->data;
        newNode->next = nullptr;

        Node *newFirst = newNode;
        Node *newLast = newNode;

        source = source->next;

        // Copy remaining nodes
        while (source != sourceFirst)
        {
            newNode = new Node;

            newNode->data = source->data;
            newNode->next = nullptr;

            newLast->next = newNode;
            newLast = newNode;

            source = source->next;
        }

        // Make new list circular
        newLast->next = newFirst;

        // Update last
        last = newLast;

        return *this;
    }
};