//Student ID: 1551024
//Student Name: Mai Thieu Nhan

#include <iostream>
#include <limits.h>

#define V 8

using namespace std;

int minDistance(int dist[], bool sptSet[])
{
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
	if (sptSet[v] == false && dist[v] <= min)
		min = dist[v], min_index = v;

	return min_index;
}

void printSolution(int dist[], int n, int prev[], int src)
{
	cout << "Vertex\tDistance from " << src << "\tPath" << endl;
	for (int i = 0; i < V; i++)
	{
		if (dist[i] == INT_MAX) cout << i << "\t" << "infinitive" << "\t\t" << prev[i] << endl;
		else cout << i << "\t" << dist[i] << "\t\t\t" << prev[i] << endl;
	}

}


void dijkstra(int graph[V][V], int src)
{
	int dist[V];
	int prev[V];
	bool sptSet[V];
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false, prev[i] = -1;
	dist[src] = 0;
	prev[src] = src;
	for (int count = 0; count < V - 1; count++)
	{
		int u = minDistance(dist, sptSet);
		sptSet[u] = true;
		for (int v = 0; v < V; v++)
		if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
			&& dist[u] + graph[u][v] < dist[v])
		{
			dist[v] = dist[u] + graph[u][v];
			prev[v] = u;
		}
	}

	printSolution(dist, V, prev, src);
}

int main()
{
	//create a random graph on website 
	int graph[V][V] =
	{
		{ 0, 3, 4, 5, 0, 0, 0, 0 },
		{ 3, 0, 7, 0, 0, 6, 0, 0 },
		{ 4, 7, 0, 0, 5, 0, 0, 0 },
		{ 5, 0, 0, 0, 0, 9, 0, 5 },
		{ 0, 0, 5, 0, 0, 0, 0, 0 },
		{ 0, 6, 0, 9, 0, 0, 0, 4 },
		{ 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 5, 0, 4, 0, 0 }
	};

	dijkstra(graph, 0);

	return 0;
}