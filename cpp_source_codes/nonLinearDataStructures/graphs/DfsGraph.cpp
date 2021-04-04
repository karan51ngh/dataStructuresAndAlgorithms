#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
class Graph
{
private:
	int V;
	vector<bool> visitLabel;
	vector<vector<int>> NodeList; //list of nodes
public:
	Graph(int);
	void addNode();
	void addEdge(int, int);
	void printGraph();
	void init_visit_label();
	void DFS(int i)
	{ //taking source to be 0;
		// cout << "entered DFS\n";
		if (i == 0)
		{
			// cout << "entered DFS if\n";
			init_visit_label();
			visitLabel[i] = 1;
			cout << 0 << " ";
		}

		for (auto itr = NodeList[i].begin(); itr < NodeList[i].end(); itr++)
		{
			// cout << "entered DFS for\n";
			if (visitLabel[*itr] == 0)
			{
				visitLabel[*itr] = 1;
				cout << *itr << " ";
				DFS(*itr);
			}
			else
				continue;
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
	g1.DFS(0);
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