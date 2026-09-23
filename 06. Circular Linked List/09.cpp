// In question 1, define a method to delete a specific node.


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
        if (last == nullptr)
            return;

        if (last->next == last)
        {
            delete last;
            last = nullptr;
            return;
        }

        Node *temp = last->next;

        while (temp->next != last)
        {
            temp = temp->next;
        }

        temp->next = last->next;

        delete last;

        last = temp;
    }

    void deleteNode(int item)
    {
        // Empty list
        if (last == nullptr)
            return;

        Node *first = last->next;
        Node *previous = last;
        Node *current = first;

        do
        {
            // Node found
            if (current->data == item)
            {
                // Only one node
                if (current == last && current == first)
                {
                    delete current;
                    last = nullptr;
                    return;
                }

                // Deleting first node
                if (current == first)
                {
                    last->next = current->next;
                    delete current;
                    return;
                }

                // Deleting last node
                if (current == last)
                {
                    previous->next = current->next;
                    delete current;
                    last = previous;
                    return;
                }

                // Deleting middle node
                previous->next = current->next;
                delete current;
                return;
            }

            previous = current;
            current = current->next;

        } while (current != first);
    }
};