#include <iostream>
#include <list>
#include <stack>

using namespace std;

class Graph
{
	int V;
	list<int> *adj;
	void DFSUtil(int v, bool visited[]);
	Graph getTranspose();
	void fillOrder(int v, bool visited[], stack<int> & Stack);
public:
	Graph(int V);
	void addEdge(int v, int w);
	void DFS(int v);
	void BFS(int s);
	void printSCCs();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

void Graph::DFSUtil(int v, bool visited[])
{
	visited[v] = true;
	cout << v << " ";

	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
	if (!visited[*i])
		DFSUtil(*i, visited);
}

void Graph::DFS(int v)
{
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;
	DFSUtil(v, visited);
}

void Graph::BFS(int s)
{
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;
	list<int> queue;

	visited[s] = true;
	queue.push_back(s);

	list<int>::iterator i;

	while (!queue.empty())
	{
		s = queue.front();
		cout << s << " ";
		queue.pop_front();
		for (i = adj[s].begin(); i != adj[s].end(); ++i)
		{
			if (!visited[*i])
			{
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
}

Graph Graph::getTranspose()
{
	Graph g(V);
	for (int v = 0; v < V; v++)
	{
		list<int>::iterator i;
		for (i = adj[v].begin(); i != adj[v].end(); ++i)
		{
			g.adj[*i].push_back(v);
		}
	}
	return g;
}

void Graph::fillOrder(int v, bool visited[], stack<int> & Stack)
{
	visited[v] = true;
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
	if (!visited[*i])
		fillOrder(*i, visited, Stack);
	Stack.push(v);
}

void Graph::printSCCs()
{
	stack<int> Stack;
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;
	for (int i = 0; i < V; i++)
	if (visited[i] == false)
		fillOrder(i, visited, Stack);

	Graph gr = getTranspose();
	for (int i = 0; i < V; i++)
		visited[i] = false;

	while (Stack.empty() == false)
	{
		int v = Stack.top();
		Stack.pop();
		if (visited[v] == false)
		{
			gr.DFSUtil(v, visited);
		}
	}
}

int main()
{
	Graph g(6);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	g.addEdge(3, 5);
	// Create a graph

	cout << endl << "Following is Depth First Traversal (starting from vertex 2):";
	g.DFS(2);
	cout << endl << "Following is Breadth First Traversal (starting from vertex 2):";
	g.BFS(2);
	cout << endl << "Connected components:";
	g.printSCCs();
	cout << endl;
	return 0;
}