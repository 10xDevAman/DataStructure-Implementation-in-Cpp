// In question 1, define a destructor to deallocates memory

#include <iostream>
using namespace std;

class Graph
{
private:
    int v_count;
    int e_count;
    int** adj;

public:
    // Create graph
    void createGraph()
    {
        cout << "Enter number of vertices: ";
        cin >> v_count;

        cout << "Enter number of edges: ";
        cin >> e_count;

        adj = new int*[v_count];

        for (int i = 0; i < v_count; i++)
            adj[i] = new int[v_count];

        // Initialize matrix
        for (int i = 0; i < v_count; i++)
        {
            for (int j = 0; j < v_count; j++)
                adj[i][j] = 0;
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

    // Print graph matrix
    void printGraph()
    {
        cout << "\nAdjacency Matrix:\n";

        for (int i = 0; i < v_count; i++)
        {
            for (int j = 0; j < v_count; j++)
                cout << adj[i][j] << " ";

            cout << endl;
        }
    }

    // Rotate matrix 90 degrees anticlockwise
    void leftRotate()
    {
        int** temp = new int*[v_count];

        for (int i = 0; i < v_count; i++)
            temp[i] = new int[v_count];

        for (int i = 0; i < v_count; i++)
        {
            for (int j = 0; j < v_count; j++)
                temp[i][j] = adj[j][v_count - 1 - i];
        }

        for (int i = 0; i < v_count; i++)
        {
            for (int j = 0; j < v_count; j++)
                adj[i][j] = temp[i][j];
        }

        for (int i = 0; i < v_count; i++)
            delete[] temp[i];

        delete[] temp;
    }

    // Check whether a vertex is isolated
    bool isIsolated(int vertex)
    {
        for (int i = 0; i < v_count; i++)
        {
            if (adj[vertex][i] != 0)
                return false;
        }

        return true;
    }

    // Destructor
    ~Graph()
    {
        for (int i = 0; i < v_count; i++)
        {
            delete[] adj[i];
        }

        delete[] adj;
    }
};

int main()
{
    Graph g;

    g.createGraph();

    cout << "\nOriginal Graph:";
    g.printGraph();

    int vertex;

    cout << "\nEnter vertex to check: ";
    cin >> vertex;

    if (g.isIsolated(vertex))
        cout << "Vertex is isolated.";
    else
        cout << "Vertex is not isolated.";

    return 0;
}