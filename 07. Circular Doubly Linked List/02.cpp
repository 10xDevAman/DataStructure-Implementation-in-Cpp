// In question 1, define a constructor to initialise start pointer with NULL.


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
        start = NULL;
    }
};

int main()
{
    CDLL list;

    return 0;
}