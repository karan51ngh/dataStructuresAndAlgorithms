#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
class Queue
{
private:
    vector<int> Q;

public:
    Queue()
    {
    }
    void enque(int x)
    {
        Q.insert(Q.begin(), x);
    }
    int deque()
    {
        int x = *(Q.end() - 1);
        Q.pop_back();
        return x;
    }
    bool isEmpty()
    {
        if (Q.begin() == Q.end())
            return 1;
        else
            return 0;
    }
};
class Graph
{
private:
    int V;
    vector<vector<int>> NodeList; //list of nodes
    vector<int> D;                //distance of each node from the source node
    Queue Q;                      //Queue used in BFS
    vector<bool> visitLabel;

public:
    Graph(int);
    void addNode();
    void addEdge(int, int);
    void printGraph();
    void init_visit_label();
    void init_distance_label();
    void BFS()
    {
        //taking source to be 0
        init_visit_label();
        init_distance_label();
        Q.enque(0);
        D[0] = 0;
        visitLabel[0] = 1;
        while (Q.isEmpty() != 1)
        {
            int head = Q.deque();
            for (auto itr = NodeList[head].begin(); itr < NodeList[head].end(); itr++)
            {
                if (visitLabel[*itr] == 1)
                    continue;
                else
                {
                    Q.enque(*itr);
                    D[*itr] = D[head] + 1;
                    visitLabel[*itr] = 1;
                }
            }
        }
    }
    void PrintDistance()
    {
        for (auto itr = D.begin(); itr < D.end(); itr++)
        {
            cout << *itr << " ";
        }
    }
};
int main()
{
    Graph g1(6);
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 3);
    g1.addEdge(2, 1);
    g1.addEdge(2, 4);
    // g1.addEdge(4, 3);
    // g1.addNode();
    g1.addEdge(4, 5);
    g1.printGraph();
    g1.BFS();
    g1.PrintDistance();
    cout << endl;
}

void Graph::printGraph()
{
    for (int i = 0; i < V; i++)
    {
        cout << i << "->    ";
        for (auto itr = NodeList[i].begin(); itr < NodeList[i].end(); itr++)
        {
            cout << *itr << "->";
        }
        cout << "NULL\n";
    }
}
void Graph::addEdge(int i, int j)
{
    NodeList[i].push_back(j);
    NodeList[j].push_back(i);
}
void Graph::addNode()
{
    V++;
    vector<int> temp;
    NodeList.push_back(temp);
}
Graph::Graph(int v)
{
    V = v;
    for (int i = 0; i < V; i++)
    {
        vector<int> temp;
        NodeList.push_back(temp);
    }
}
void Graph::init_visit_label()
{
    for (int i = 0; i < V; i++)
    {
        visitLabel.push_back(0);
    }
}
void Graph::init_distance_label()
{
    for (int i = 0; i < V; i++)
    {
        D.push_back(INT_MAX);
    }
}