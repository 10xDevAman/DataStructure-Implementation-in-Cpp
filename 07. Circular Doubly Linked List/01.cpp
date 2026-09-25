// Define a class CDLL to implement Circular Doubly linked list data structure with member variable start pointer of type node.


#include <iostream>
using namespace std;

class CDLL
{
private:
    // Node structure
    struct node
    {
        int data;
        node* prev;
        node* next;
    };

    // Start pointer
    node* start;

public:
    // Constructor
    CDLL()
    {
        start = nullptr;
    }
};

int main()
{
    CDLL list;

    return 0;
}