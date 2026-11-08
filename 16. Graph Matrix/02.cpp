// In Question 1, define a method createGraph() to create and store adjacent node information.

#include <iostream>
using namespace std;

class Graph
{
private:
    int v_count;
    int e_count;
    int** adj;

public:
    void createGraph()
    {
        cout << "Enter number of vertices: ";
        cin >> v_count;

        cout << "Enter number of edges: ";
        cin >> e_count;

        // Allocate memory for adjacency matrix
        adj = new int*[v_count];

        for (int i = 0; i < v_count; i++)
        {
            adj[i] = new int[v_count];
        }

        // Initialize matrix with 0
        for (int i = 0; i < v_count; i++)
        {
            for (int j = 0; j < v_count; j++)
            {
                adj[i][j] = 0;
            }
        }

        // Input edges
        int u, v;

        for (int i = 0; i < e_count; i++)
        {
            cout << "Enter edge (source destination): ";
            cin >> u >> v;

            adj[u][v] = 1;
            adj[v][u] = 1;
        }
    }
};

int main()
{
    Graph g;

    g.createGraph();

    return 0;
}