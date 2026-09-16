// In question 1, define a constructor to initialise start pointer with NULL.


#include <iostream>
using namespace std;

// Node
class Node
{
public:
    int data;
    Node *next;
};

// Singly Linked List
class SLL
{
private:
    Node *start;

public:
    // Constructor
    SLL()
    {
        start = NULL;
    }
};

int main()
{
    SLL list;

    return 0;
}