// In question 1, define a constructor to initialise start pointer with NULL.


#include <iostream>
using namespace std;

// Node
class Node
{
public:
    Node *prev;
    int data;
    Node *next;
};

// Doubly Linked List
class DLL
{
private:
    Node *start;

public:
    // Constructor
    DLL()
    {
        start = NULL;
    }
};

int main()
{
    DLL list;

    return 0;
}