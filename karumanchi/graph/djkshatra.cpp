// Program to find Dijkstra's shortest path using STL set
#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f
  
// This class represents a directed graph using 
// adjacency list representation
class Graph
{
    int V; // Number of vertices
    list <pair<int, int>> *adj; // Could be done by vectors too
public:
    Graph(int V); // Constructor
  
    // Add edge to graph
    void addEdge(int u, int v, int w);
  
    // Print shortest path
    void shortestPath(int s);
};
  
// Allocates memory for adjacency list
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<pair<int, int>>[V];
}
  
void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}
  
// Prints shortest paths from src to all other vertices
void Graph::shortestPath(int src)
{   
    // processed elements of set
    set<pair<int, int>> setds;

    // vector for distance, initialize with infinity
    vector <int> dist(V, INF);

    // Insert Source
    setds.insert((0, src));
    dist[src] = 0;

    while (!setds.empty()) {
        // Extract the minimum distance vertex
        pair<int, int> tmp =  *(setds.begin());
        setds.erase(setds.begin());

        // vertex label is stored in second of pair
        int u = tmp.second;

        // Iterate for all neighbour
        list <pair<int, int>>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i) {
            int v = (*i).first;
            int weight = (*i).second;

            if (dist[v] > dist[u] + weight) {
                if (dist[v] != INF) 
                    setds.erase(setds.find((dist[v], v)));
                dist[v] = dist[u] + weight;
                setds.insert(make_pair(dist[v], v));

            }
        }

        printf("vertex distance from source:\n");
        for (int i=0; i<V; i++) {
            printf("%d \t\t %d\n", i, dist[i]);
        }

    }

}


  
// Driver program to test methods of graph class
int main()
{
    // create the graph given in above fugure
    int V = 9;
    Graph g(V);
  
    //  making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
  
    g.shortestPath(0);
  
    return 0;
}