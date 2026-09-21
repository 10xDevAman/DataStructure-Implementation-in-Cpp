// Define a class CLL to implement Circular linked list data structure with member variable last pointer of type node.


#include <iostream>
using namespace std;

// Node
class Node
{
public:
    int data;
    Node *next;
};

// Circular Linked List
class CLL
{
private:
    Node *last;
};

int main()
{
    CLL list;

    return 0;
}