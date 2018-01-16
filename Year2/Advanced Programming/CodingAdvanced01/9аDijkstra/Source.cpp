#include <vector>
#include <iostream>
#include <map>
#include <set>
const int INF = 1000000000;

using namespace std;

void printPathTo(int from, int to, vector<int>& ancestors, vector<int>& distances);
int populateGraph(int edgesCount, map<int, vector<pair<int, int>>>& graph); //returns graph's size
void djikstra(map<int, vector<pair<int, int>>>& graph, int s); //s is for start

int main()
{
	map<int, vector<pair<int, int>>> graph;

	//read graph
	int edges;
	while (cin >> edges)
	{
		const int vertices = populateGraph(edges, graph);

		for (int i = 1; i <= vertices; ++i)
		{
			djikstra(graph, i);
		}

		map<int, vector<pair<int, int>>> newGraph;
		graph = newGraph;
	}
}


int populateGraph(int edgesCount, map<int, vector<pair<int, int>>>& graph)
{
	for (int i = 0; i < edgesCount; ++i)
	{
		int first, second, weight;
		cin >> first >> second >> weight;

		if (graph.find(first) == graph.end())
		{
			//not found, then create
			vector<pair<int, int>> newV;
			graph.insert(std::pair<int, vector<pair<int, int>>>(first, newV));
		}
		if (graph.find(second) == graph.end())
		{
			//not found, then create
			vector<pair<int, int>> newV;
			graph.insert(std::pair<int, vector<pair<int, int>>>(second, newV));
		}

		graph[first].push_back(std::pair<int, int>(second, weight));
	}

	return graph.size();
}

void djikstra(map<int, vector<pair<int, int>>>& graph, int s) //s is for start
{
	const int n = graph.size();

	vector<int> distances(n + 1, INF);
	vector<int> ancestors(n + 1, -1); //holds the previous element to v in ancestors[v] (via which we ended up in v)
	vector<bool> visited(n + 1);


	distances[s] = 0;
	distances[0] = -1;
	visited[0] = true;

	for (int i = 1; i <= n; ++i)
	{
		int v = -1;

		for (int j = 1; j <= n; ++j)
		{
			if (!visited[j] && (v == -1 || distances[j] < distances[v]))
				v = j;
		}

		if (distances[v] == INF) break;

		visited[v] = true;

		auto adjacents = graph[v];

		for (size_t j = 0; j < adjacents.size(); ++j)
		{
			int to = graph[v][j].first;
			int weight = graph[v][j].second;

			if (distances[v] + weight < distances[to])
			{
				distances[to] = distances[v] + weight;
				ancestors[to] = v;
			}
		}
	}

	printPathTo(1, n, ancestors, distances);
}

void printPathTo(int from, int to, vector<int>& ancestors, vector<int>& distances)
{
	if (distances[from] == INF) distances[from] = -1;

	cout << distances[from];
	for (int i = from + 1; i <= to; ++i)
	{
		if (distances[i] == INF) distances[i] = -1;

		cout << " " << distances[i];
	}

	cout << endl;
}
