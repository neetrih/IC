#include <iostream>
#include <vector>

using namespace std;

class Graph
{
private:
	int V;
	vector<int> *adj;
public:
	Graph(int V)
{
	this->V = V;
	adj = new vector<int>[V];
}
	void addEdge(int v, int w)
{
	adj[v].push_back(w);
	adj[w].push_back(v);
}
	vector<int> getAdj(int v)
{
	return adj[v];
}
};

int main()
{
	Graph g(5);
	g.addEdge(0, 1);
	g.addEdge(0, 4);
	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(1, 4);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	
	for (int i = 0; i < 5; i++) {
		vector<int> adj = g.getAdj(i);
		cout << "Vertex " << i << ": ";
		for (int j = 0; j < adj.size(); j++) {
			cout << adj[j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}
