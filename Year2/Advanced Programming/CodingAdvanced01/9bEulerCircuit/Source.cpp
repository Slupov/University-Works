#include <stdio.h>
#include<iostream>
#include <vector>
using namespace std;

unsigned vertices;

void eulerCircuit(int v, vector<vector<bool>>& graph);
void populate_graph(const int edges, vector<vector<bool>>& graph);

int main()
{
	int tests;
	cin >> tests;

	for (int i = 0; i < tests; i++)
	{
		cin >> vertices;
		long edges;
		cin >> edges;

		vector<bool> row(vertices);
		vector<vector<bool>> graph(vertices, row); //using adjacency matrix

		populate_graph(edges, graph);
		eulerCircuit(0, graph);
	}

	return 0;
}

void populate_graph(const int edges, vector<vector<bool>>& graph)
{
	int a, b;

	//graph input
	for (int j = 0; j < edges; j++)
	{
		cin >> a >> b;
		graph[a - 1][b - 1] = true;
		graph[b - 1][a - 1] = true;
	}
}

void printPath(const vector<int>& visited, unsigned pTop);

void eulerCircuit(int v, vector<vector<bool>>& graph)
{
	vector<int> path(vertices * vertices);
	vector<int> visited(vertices * vertices, -1);

	unsigned j, pTop = 0, vTop = 1;
	visited[vTop] = v;

	while (vTop > 0)
	{
		//get current vertex
		v = visited[vTop];
		for (j = 0; j < vertices; j++)
		{
			if (graph[v][j]) //there's an edge
			{
				graph[v][j] = false; //remove it
				v = j; //go to the adjacent
				break;
			}
		}

		if (j < vertices)
			visited[++vTop] = v; // add current vertex to eulerian circuit
		else
			path[++pTop] = visited[vTop--];
	}

	printPath(path, pTop);
}

void printPath(const vector<int>& path, unsigned pTop)
{
	for (int k = pTop; k > 0; k--)
	{
		cout << path[k] + 1 << " ";
	}
	cout << endl;
}
