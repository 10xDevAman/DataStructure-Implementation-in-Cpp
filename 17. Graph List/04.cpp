// Define createGraph() method in Graph class to allocate memory for array of AdjList Objects.


#include <iostream>
using namespace std;

class AdjList
{
public:
    int vertex;
    AdjList *next;

    // Constructor
    AdjList()
    {
        vertex = 0;
        next = NULL;
    }
};

class Graph
{
private:
    int v_count;
    int e_count;
    AdjList *adj;

public:
    // Constructor
    Graph(int v_count)
    {
        this->v_count = v_count;
        e_count = 0;
        adj = NULL;
    }

    // Method to create graph
    void createGraph()
    {
        adj = new AdjList[v_count];
    }
};

int main()
{
    Graph g(5);

    g.createGraph();

    return 0;
}
