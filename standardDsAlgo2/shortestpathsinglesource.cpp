#include <bits/stdc++.h>
using namespace std;

/*
Single Source Sortest Path Algorithms (weighted graphs) - (one source to all node distances)

1. Dijkshtra's Algorithm
2. Bellman ford algorithm

Note: “Dijkstra's algorithm” can only be used to solve the “single source shortest path” problem in a graph with non-negative weights.
since it selects the minimum edge as part of shortest path, but with negative edge, other path can be shorter!

“Bellman-Ford algorithm”, on the other hand, can solve the “single-source shortest path” in a weighted directed graph with any weights, including, of course, negative weights.

1. Dijkshatra's algorithm:
* O(V+ElogV) for a Binary heap. O(E+ VlogV) for fibonacchi heap
steps:
* define dist vector
* define priority queue which takes {dist, node} as input
* till priority queue is empty
*   pop out node
*   for all neighbours
*       if relax edges
*           relax edges
*           push nbr node and relaxed weight in queue

2. Bellman ford algorithm
* O(V⋅E) 



*/



/*
adjlist:
[ [{3, node2}, {1, node3}], [{4, node1}] ] 

Below code is for directed pair, thats why no visited is required!
*/
void djkshatra(vector<vector<pair<int,int>>> adjlist, int source) 
{
    vector<int> dist(n+1, INT_MAX);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // {dist, node}
    pq.push({0, source}); //src is k, dist of k from k is 0
    dist[source] = 0;
    
    while(!pq.empty()) {
        int node = pq.top().second; 
        int nodetime = pq.top().first;
        pq.pop();
        
        if (nodetime > dist[node]) continue; // why?
        
        for(auto &nbr: adjlist[node]) {
            int nbrv = nbr.second;
            int nbrw = nbr.first;
            
            cout << nbrv << " : " <<nbrw<< endl;
            
            if (dist[nbrv] > dist[node] + nbrw) {
                dist[nbrv] = dist[node] + nbrw;
                pq.push({dist[nbrv], nbrv});
            }
        }
    }
}


void bellmandford(int n, vector<vector<int>>& edges, int source) {
    vector<int> curr(n, INT_MAX);
    curr[source] = 0;
    for (int i=0; i<n-1; ++i) { // n-1 time relaxation + for 0 edges = total n times
        for(auto &edge: edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            curr[v] = min(curr[v], prev[u] + w);
        }
    }

    
}