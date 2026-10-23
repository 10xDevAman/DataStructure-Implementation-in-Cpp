// In question 1, define a constructor to initialise member variable.

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

public:
    // Constructor
    PriorityQueue()
    {
        start = NULL;
    }
};

int main()
{
    PriorityQueue pq;

    return 0;
}