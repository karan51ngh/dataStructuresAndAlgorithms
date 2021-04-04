//implementation where we use nodes
#include <iostream>
#include <vector>
using namespace std;

class Node
{
private:
    int data;
    static int id;

public:
    vector<Node *> AdjList;
    Node(int);
    int getData()
    {
        return data;
    }
};

class Graph
{
private:
    static int V;
    vector<Node *> NodeList;

public:
    Graph();
    void add(int);
    void add_edge(int, int);
    void print_graph();
    int get_size();
};
int main()
{
    Graph g1;
    g1.add(13); //id=0
    g1.add(45); //id=1
    g1.add(54); //id=2
    g1.add(67); //id=3
    g1.add(72); //id=4

    g1.add_edge(0, 1);
    g1.add_edge(0, 2);
    g1.add_edge(0, 3);
    g1.add_edge(2, 1);
    g1.add_edge(2, 3);
    cout << "\nsize of the graph is " << g1.get_size() << endl;
    g1.print_graph();
    cout << endl;
}

//class Node Stuff

int Node::id;

Node::Node(int x)
{
    cout << "\nNode created in memory\n";
    data = x;
    id += 1;
    cout << "id is " << id << "\n";
    cout << "data is " << data << "\n";
}

//class Graph Stuff

int Graph::V;
Graph::Graph()
{
    cout << "\nGraph created in memory\n";
}
void Graph::add(int x)
{
    Node *t = new Node(x);
    NodeList.push_back(t);
    V++;
}
void Graph::add_edge(int id1, int id2)
{
    NodeList[id1]->AdjList.push_back(NodeList[id2]);
    NodeList[id2]->AdjList.push_back(NodeList[id1]);
}
int Graph::get_size()
{
    return V;
}
void Graph::print_graph()
{
    for (int i = 0; i < V; i++)
    {
        cout << NodeList[i]->getData() << "->   ";
        for (auto itr = NodeList[i]->AdjList.begin(); itr < NodeList[i]->AdjList.end(); itr++)
        {
            cout << (*itr)->getData() << "->";
        }
        cout << endl;
    }
}
