// Define a class PriorityQueue with node type pointer start as member variable. Implement PriorityQueue using singly linked list.

#include <iostream>
using namespace std;

class PriorityQueue
{
private:
    struct node
    {
        int data;
        int priority;
        node* next;
    };

    node* start;
};

int main()
{
    PriorityQueue pq;

    return 0;
}