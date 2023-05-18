#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

class Graph
{
private:
	int V;
	vector<pair<int, int>> *adj;
public:
	Graph(int V)
{
	this->V = V;
	adj = new vector<pair<int, int>>[V];
}
	void addEdge(int u, int v, int weight)
{
	adj[u].push_back(make_pair(v, weight));
	adj[v].push_back(make_pair(u, weight));
}
	
	void prim()
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<bool> visited(V, false);
	vector<int> key(V, INF);
	vector<int> parent(V, -1);
	
	int src = 0;
	pq.push(make_pair(0, src));
	key[src] = 0;
	
	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		
		visited[u] = true;
		
		vector<pair<int, int>> adjv = adj[u];
		for (int i = 0; i < adjv.size(); i++) {
			int v = adjv[i].first;
			int weight = adjv[i].second;
			
			if (!visited[v] && weight < key[v]) {
				key[v] = weight;
				pq.push(make_pair(key[v], v));
				parent[v] = u;
			}
		}
	}
	
	cout << "Edges in MST: " << endl;
	for (int i = 1; i < V; i++) {
		cout << parent[i] << " - " << i << endl;
	}
}
};

int main()
{
	Graph g(5);
	g.addEdge(0, 1, 4);
	g.addEdge(0, 2, 2);
	g.addEdge(1, 2, 3);
	g.addEdge(1, 3, 2);
	g.addEdge(1, 4, 3);
	g.addEdge(2, 3, 5);
	g.addEdge(3, 4, 1);
	
	g.prim();
	
	return 0;
}
