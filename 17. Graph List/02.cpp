// Define appropriate constructors in the classes AdjList and Graph


#include <iostream>
using namespace std;

class AdjList
{
public:
    int vertex;
    AdjList *next;

    // Default constructor
    AdjList()
    {
        vertex = 0;
        next = NULL;
    }

    // Parameterized constructor
    AdjList(int vertex)
    {
        this->vertex = vertex;
        next = NULL;
    }
};

class Graph
{
private:
    int v_count;
    int e_count;
    AdjList **adj;

public:
    // Parameterized constructor
    Graph(int v_count)
    {
        this->v_count = v_count;
        e_count = 0;

        adj = new AdjList*[v_count];

        for (int i = 0; i < v_count; i++)
        {
            adj[i] = NULL;
        }
    }
};

int main()
{
    Graph g(5);

    return 0;
}
