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
	
	void DFSUtil(int v, bool *visited)
{
	visited[v] = true;
	cout << v << " ";
	
	vector<int> adjv = adj[v];
	for (int i = 0; i < adjv.size(); i++) {
		if (!visited[adjv[i]]) {
			DFSUtil(adjv[i], visited);
		}
	}
}
	
	void DFS(int s)
{
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++) {
		visited[i] = false;
	}
	
	DFSUtil(s, visited);
	cout << endl;
	
	delete[] visited;
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
	
	cout << "DFS traversal starting from vertex 1: ";
	g.DFS(1);
	
	return 0;
}
