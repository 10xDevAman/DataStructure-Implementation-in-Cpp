// Define a class Graph using matrix representation with v_count, e_count and adj pointer as instance members.


#include <iostream>
using namespace std;

class Graph
{
private:
    int v_count;
    int e_count;
    int **adj;

public:
    Graph(int v_count)
    {
        this->v_count = v_count;
        e_count = 0;

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
    }
};
