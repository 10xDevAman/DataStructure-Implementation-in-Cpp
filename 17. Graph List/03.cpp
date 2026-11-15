// In question 1, define a method to print graph matrix.


#include <iostream>
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

    // Method to print graph matrix
    void printMatrix()
    {
        cout << "Adjacency Matrix:" << endl;

        for (int i = 0; i < v_count; i++)
        {
            for (int j = 0; j < v_count; j++)
            {
                cout << adj[i][j] << " ";
            }

            cout << endl;
        }
    }
};

int main()
{
    Graph g(4);

    g.printMatrix();

    return 0;
}
