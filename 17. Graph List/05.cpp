// Define a method addEdge() in Graph class to add a new node in adjacency list. 


#include <iostream>
using namespace std;

class AdjList
{
public:
    int vertex;
    AdjList *next;

    AdjList()
    {
        vertex = 0;
        next = NULL;
    }

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
    AdjList *adj;

public:
    // Constructor
    Graph(int v_count)
    {
        this->v_count = v_count;
        e_count = 0;
        adj = NULL;
    }

    // Create graph
    void createGraph()
    {
        adj = new AdjList[v_count];
    }

    // Add edge
    void addEdge(int source, int destination)
    {
        // Validate vertices
        if (source < 0 || source >= v_count ||
            destination < 0 || destination >= v_count)
        {
            cout << "Invalid vertex!" << endl;
            return;
        }

        // Create new adjacency node
        AdjList *n = new AdjList(destination);

        // Insert node at beginning
        n->next = adj[source].next;
        adj[source].next = n;

        e_count++;
    }
};

int main()
{
    Graph g(4);

    g.createGraph();

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);

    return 0;
}
