// Define a method to print graph (print values of adjacency list).


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

    // Print graph
    void printGraph()
    {
        if (adj == NULL)
        {
            cout << "Graph is not created!" << endl;
            return;
        }

        for (int i = 0; i < v_count; i++)
        {
            cout << i << " -> ";

            AdjList *temp = adj[i].next;

            while (temp != NULL)
            {
                cout << temp->vertex << " -> ";
                temp = temp->next;
            }

            cout << "NULL" << endl;
        }
    }

    // Destructor
    ~Graph()
    {
        if (adj != NULL)
        {
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

    g.printGraph();

    return 0;
}
