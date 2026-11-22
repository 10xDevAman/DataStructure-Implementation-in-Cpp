// Implement DFS in Graph list representation

#include <iostream>
using namespace std;

class Graph
{
    int v_count;
    int e_count;
    AdjList *adj;

public:
    void DFS(int start)
    {
        bool *visited = new bool[v_count];

        for (int i = 0; i < v_count; i++)
            visited[i] = false;

        DFSHelper(start, visited);

        delete[] visited;
    }

private:
    void DFSHelper(int vertex, bool visited[])
    {
        visited[vertex] = true;

        cout << vertex << " ";

        node *temp = adj[vertex].start;

        while (temp != NULL)
        {
            int neighbour = temp->data;

            if (!visited[neighbour])
                DFSHelper(neighbour, visited);

            temp = temp->next;
        }
    }
};