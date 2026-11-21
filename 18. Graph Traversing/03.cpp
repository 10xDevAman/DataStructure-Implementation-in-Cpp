// Implement BFS in Graph list representation


#include <iostream>
#include <queue>
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
        if (adj != NULL)
            return;

        adj = new AdjList[v_count];
    }

    // Add edge (Undirected Graph)
    void addEdge(int source, int destination)
    {
        if (adj == NULL)
        {
            cout << "Graph is not created!" << endl;
            return;
        }

        if (source < 0 || source >= v_count ||
            destination < 0 || destination >= v_count)
        {
            cout << "Invalid vertex!" << endl;
            return;
        }

        AdjList *n = new AdjList(destination);

        n->next = adj[source].next;
        adj[source].next = n;

        // Add reverse edge
        n = new AdjList(source);

        n->next = adj[destination].next;
        adj[destination].next = n;

        e_count++;
    }

    // BFS Traversal
    void BFS(int start)
    {
        if (adj == NULL || start < 0 || start >= v_count)
        {
            cout << "Invalid graph or starting vertex!" << endl;
            return;
        }

        bool *visited = new bool[v_count];

        for (int i = 0; i < v_count; i++)
        {
            visited[i] = false;
        }

        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal: ";

        while (!q.empty())
        {
            int current = q.front();
            q.pop();

            cout << current << " ";

            AdjList *temp = adj[current].next;

            while (temp != NULL)
            {
                int neighbor = temp->vertex;

                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }

                temp = temp->next;
            }
        }

        delete[] visited;
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
    g.addEdge(2, 3);

    g.BFS(0);

    return 0;
}
