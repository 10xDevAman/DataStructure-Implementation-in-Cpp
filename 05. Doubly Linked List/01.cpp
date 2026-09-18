// Define a class DLL to implement singly linked list data structure with member variable start pointer of type node.


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
};

int main()
{
    DLL list;

    return 0;
}