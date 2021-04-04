//implementation where we also store edge weigths
#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
class Graph
{
private:
    int V;
    vector<vector<tuple<int, int>>> NodeList;

public:
    Graph(int v)
    {
        V = v;
        for (int i = 0; i < V; i++)
        {
            vector<tuple<int, int>> temp;
            NodeList.push_back(temp);
        }
    }
    void addEdge(int i, int j, int w)
    {
        tuple<int, int> temp1, temp2;
        temp1 = make_tuple(j, w);
        temp2 = make_tuple(i, w);
        NodeList[i].push_back(temp1);
        NodeList[j].push_back(temp2);
    }
    void printGraph()
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << "->    ";
            for (auto itr = NodeList[i].begin(); itr < NodeList[i].end(); itr++)
            {
                cout << get<0>(*itr) << ", " << get<1>(*itr) << " "
                     << "->";
            }
            cout << "NULL" << endl;
        }
    }
};
int main()
{
    Graph g1(5);
    int ch = 1;
    int choice;
    int I, J, W;
    while (ch)
    {
        cout << "what u wanna do? enter choice";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "enter the node 1 and node 2 and the weight\n";
            cin >> I >> J >> W;
            g1.addEdge(I, J, W);
            ch = 1;
            break;
        case 2:
            g1.printGraph();
            ch = 0;
            cout << endl;
            break;
        }
    }
}