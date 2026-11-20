// Implement BFS in Graph Matrix.



#include <iostream>
#include <queue>
using namespace std;

class Graph
{
private:
    int v_count;
    int e_count;
    int **adj;

public:
    // Constructor
    Graph(int v_count)
    {
        this->v_count = v_count;
        e_count = 0;

        adj = new int*[v_count];

        for (int i = 0; i < v_count; i++)
        {
            adj[i] = new int[v_count];

            for (int j = 0; j < v_count; j++)
            {
                adj[i][j] = 0;
            }
        }
    }

    // Add edge (Undirected Graph)
    void addEdge(int source, int destination)
    {
        if (source < 0 || source >= v_count ||
            destination < 0 || destination >= v_count)
        {
            cout << "Invalid vertex!" << endl;
            return;
        }

        if (adj[source][destination] == 0)
        {
            adj[source][destination] = 1;
            adj[destination][source] = 1;
            e_count++;
        }
    }

    // BFS Traversal
    void BFS(int start)
    {
        if (start < 0 || start >= v_count)
        {
            cout << "Invalid starting vertex!" << endl;
            return;
        }

        bool *visited = new bool[v_count];

        // Initialize visited array
        for (int i = 0; i < v_count; i++)
        {
            visited[i] = false;
        }

        queue<int> q;

        // Visit starting vertex
        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal: ";

        while (!q.empty())
        {
            int current = q.front();
            q.pop();

            cout << current << " ";

            // Visit adjacent vertices
            for (int i = 0; i < v_count; i++)
            {
                if (adj[current][i] == 1 && !visited[i])
                {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }

        delete[] visited;
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
    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);

    g.BFS(0);

    return 0;
}
