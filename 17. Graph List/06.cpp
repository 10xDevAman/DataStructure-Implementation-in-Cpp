// Define destructors in the classes AdjList and Graph


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

    // Destructor
    ~AdjList()
    {
        // No dynamic memory allocated directly here
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
        if (source < 0 || source >= v_count ||
            destination < 0 || destination >= v_count)
        {
            cout << "Invalid vertex!" << endl;
            return;
        }

        AdjList *n = new AdjList(destination);

        n->next = adj[source].next;
        adj[source].next = n;

        e_count++;
    }

    // Destructor
    ~Graph()
    {
        if (adj != NULL)
        {
            // Delete dynamically allocated linked-list nodes
            for (int i = 0; i < v_count; i++)
            {
                AdjList *temp = adj[i].next;

                while (temp != NULL)
                {
                    AdjList *nextNode = temp->next;
                    delete temp;
                    temp = nextNode;
                }
            }

            // Delete array of AdjList objects
            delete[] adj;
        }
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
