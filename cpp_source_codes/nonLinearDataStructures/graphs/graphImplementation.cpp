// implementation of adjacency List using vector
// basic implementation
#include <iostream>
#include <vector>
using namespace std;

class Graph
{
private:
    int V;
    vector<int> *adj = NULL;

public:
    Graph(int v)
    {
        V = v;
        adj = new vector<int>[V];
    }
    void addEdge(int i, int j)
    {
        adj[i].push_back(j);
        adj[j].push_back(i);
    }
    void printGraph()
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << "->";
            for (auto it = adj[i].begin(); it < adj[i].end(); it++)
            {
                cout << *it << "->";
            }
            cout << endl;
        }
    }
};
int main()
{
    Graph g1(5);
    g1.addEdge(0, 1);
    g1.addEdge(2, 1);
    g1.addEdge(3, 1);
    g1.addEdge(3, 2);
    g1.addEdge(0, 4);
    g1.addEdge(1, 4);
    g1.addEdge(3, 4);
    g1.printGraph();
}