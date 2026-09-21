// In question 1, define a constructor to initialise last pointer with NULL.


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
};