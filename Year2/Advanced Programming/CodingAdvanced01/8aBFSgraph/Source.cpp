#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>

#define FN 82264
using namespace std;

void populateMap(map<int, set<int>>& nodesWithNeighbours);
void print(unordered_set<int> visited);
void BFS(int i, map<int, set<int>>& nodesWithNeighbours);

int main()
{
	map<int, set<int>> nodesWithNeighbours; //node, neighbours
	populateMap(nodesWithNeighbours);

	int from = 1 + FN % nodesWithNeighbours.size();
	BFS(from, nodesWithNeighbours);
	return 0;
}

void populateMap(map<int, set<int>>& nodesWithNeighbours)
{
	int verticesCount;
	cin >> verticesCount;

	for (int i = 0; i < verticesCount; ++i)
	{
		//nodes input
		int first, second;
		cin >> first >> second;

		if (nodesWithNeighbours.find(first) == nodesWithNeighbours.end())
		{
			//not found, then create
			set<int> newSet;
			nodesWithNeighbours.insert(std::pair<int, set<int>>(first, newSet));
		}
		if (nodesWithNeighbours.find(second) == nodesWithNeighbours.end())
		{
			//not found, then create
			set<int> newSet;
			nodesWithNeighbours.insert(std::pair<int, set<int>>(second, newSet));
		}

		nodesWithNeighbours[first].insert(second);
		nodesWithNeighbours[second].insert(first);
	}
}

void BFS(int i, map<int, set<int>>& nodesWithNeighbours)
{
	unordered_set<int> visited;
	queue<int> queue;

	visited.insert(i);

	do
	{
		set<int> adjacents = nodesWithNeighbours[i];

		for (auto adjacent : adjacents)
		{
			if (visited.find(adjacent) == visited.end())
			{
				//not found
				queue.push(adjacent);
			}
		}

		i = queue.front();
		visited.insert(queue.front());
		queue.pop();
	}
	while (queue.size() > 0);

	print(visited);
}

void print(unordered_set<int> visited)
{
	auto previousEnd = visited.end();
	--previousEnd;

	for (unordered_set<int>::iterator it = visited.begin(); it != previousEnd; ++it)
	{
		cout << *it << " ";
	}

	cout << *previousEnd << endl;
}
