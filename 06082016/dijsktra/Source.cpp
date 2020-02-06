#include <iostream>
#include <stdio.h>
#include <limits.h>

#define V 8

int minDistance(int dist[], bool sptSet[])
{
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
	if (sptSet[v] == false && dist[v] <= min)
		min = dist[v], min_index = v;

	return min_index;
}

void printSolution(int dist[], int n, int prev[])
{
	printf("Vertex\tDistance from Source\tPath\n");
	for (int i = 0; i < V; i++)
		printf("%d \t\t%d  \t\t%d\n", i, dist[i],prev[i]);
	cout << endl;
}

// Funtion that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int graph[V][V], int src)
{
	int dist[V];     // The output array.  dist[i] will hold the shortest
	// distance from src to i
	
	int prev[V];

	bool sptSet[V]; // sptSet[i] will true if vertex i is included in shortest
	// path tree or shortest distance from src to i is finalized

	// Initialize all distances as INFINITE and stpSet[] as false
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false, prev[i] = -1;

	// Distance of source vertex from itself is always 0
	dist[src] = 0;
	prev[src] = src;

	// Find shortest path for all vertices
	for (int count = 0; count < V - 1; count++)
	{
		// Pick the minimum distance vertex from the set of vertices not
		// yet processed. u is always equal to src in first iteration.
		int u = minDistance(dist, sptSet);

		// Mark the picked vertex as processed
		sptSet[u] = true;

		// Update dist value of the adjacent vertices of the picked vertex.
		for (int v = 0; v < V; v++)

			// Update dist[v] only if is not in sptSet, there is an edge from 
			// u to v, and total weight of path from src to  v through u is 
			// smaller than current value of dist[v]
		if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
			&& dist[u] + graph[u][v] < dist[v])
		{
			dist[v] = dist[u] + graph[u][v];
			prev[v] = u;
		}
	}

	// print the constructed distance array
	printSolution(dist, V, prev);
}

// driver program to test above function
int main()
{
	/* Let us create the example graph discussed above */
	int graph[V][V] = {
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