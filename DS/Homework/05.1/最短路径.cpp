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
	
	void dijkstra(int s)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	
	vector<int> dist(V, INF);
	dist[s] = 0;
	
	pq.push(make_pair(dist[s], s));
	
	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		
		vector<pair<int, int>> adjv = adj[u];
		for (int i = 0; i < adjv.size(); i++) {
			int v = adjv[i].first;
			int weight = adjv[i].second;
			
			if (dist[v] > dist[u] + weight) {
				dist[v] = dist[u] + weight;
				pq.push(make_pair(dist[v], v));
			}
		}
	}
	
	cout << "Shortest distances from source vertex " << s << " are: " << endl;
	for (int i = 0; i < V; i++) {
		cout << i << ": " << dist[i] << endl;
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
	
	g.dijkstra(0);
	
	return 0;
}

