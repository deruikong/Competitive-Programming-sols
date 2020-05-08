// STL implementation of Prim's algorithm for MST 
#include<bits/stdc++.h> 
using namespace std; 
# define INF 0x3f3f3f3f 

// iPair ==> Integer Pair 
typedef pair<int, int> iPair; 

// To add an edge 
void addEdge(vector <pair<int, int> > adj[], int u, 
									int v, int wt) 
{ 
	adj[u].push_back(make_pair(v, wt)); 
	adj[v].push_back(make_pair(u, wt)); 
} 

// Prints shortest paths from src to all other vertices 
void primMST(vector<pair<int,int> > adj[], int V) 
{ 
    int tot = 0;
	priority_queue<iPair, vector <iPair> , less<iPair> > pq; 

	int src = 0;
	vector<int> key(V, -1); 

	// To store parent array which in turn store MST 
	vector<int> parent(V, -1); 

	// To keep track of vertices included in MST 
	vector<bool> inMST(V, false); 

	// Insert source itself in priority queue and initialize 
	// its key as 0. 
	pq.push(make_pair(0, src)); 
	key[src] = 0; 

	while (!pq.empty()) 
	{
        tot++;
		int u = pq.top().second; 
		pq.pop(); 

		inMST[u] = true; 
		for (auto x : adj[u]) 
		{ 
			int v = x.first; 
			int weight = x.second; 
			if (inMST[v] == false && weight > key[v]) 
			{ 
				key[v] = weight;
				pq.push(make_pair(key[v], v)); 
				parent[v] = u; 
			} 
		} 
	} 
    cout << tot << endl;
	// Print edges of MST using parent array 
	for (int i = 1; i < V; ++i) 
		printf("%d - %d\n", parent[i], i); 
} 

// Driver program to test methods of graph class 
int main() 
{ 
	int V = 5; 
	vector<iPair > adj[V]; 

	// making above shown graph 
	addEdge(adj, 0, 1, 20); 
	addEdge(adj, 0, 2, 50); 
	addEdge(adj, 0, 3, 70); 
	addEdge(adj, 0, 4, 90); 
	addEdge(adj, 1, 2, 30); 
	addEdge(adj, 2, 3, 40); 
	addEdge(adj, 3, 4, 60); 

	primMST(adj, V); 

	return 0; 
} 
