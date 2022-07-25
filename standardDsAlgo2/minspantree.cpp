#include<bits/stdc++.h>
using namespace std;

/*
For weighted undirected graph, find the edges which connect all the edges with minimum number of edges and weight. (N-1 edges only for N nodes)

1. Krushkals Algorithm - using disjoint set: sort the weights, merge using disjoint set till N-1 edges are merged
2. Prims Algorithm

1. Krushkals
* proof: cut property : minimum weight edge is selected between 2 disjoint sets of nodes which are connected internally
* sort the edges weigth and select the lowest weighted edges first. after that merge usig disjoint set
* runs faster in sparse graph (less number of edges)

Time Complexity: O(ElogE). Here, E represents the number of edges.

2. Prims Algorithm : greedy algorithm!
* start with any node
* pick one of the minimum weighted edge and carry on
* runs better in dense graph 

Time Complexity: O(E+V)*O(logV) = O(Elogv)

class cmp {
public:
    bool operator() (Edge edge1, Edge edge2) {
        return edge1.cost>edge2.cost;  
    }
};
priority_queue<int, vector<int>, cmp> pq;  // minimum weight will be on top! 
greater<int> : will put minimum at end (min heap)
less<int>: will put maximum at end (max heap)

class Edge {
public:
    int node1;
    int node2;
    int cost;
    Edge(int node1, int node2, int cost): node1(node1), node2(node2), cost(cost) {}
};
*/

class Edge {
public:
    int node1;
    int node2;
    int cost;
    Edge(int node1, int node2, int cost): node1(node1), node2(node2), cost(cost) {}
};

class cmp {
public:
    bool operator() (Edge edge1, Edge edge2) {
        return edge1.cost>edge2.cost;
    }
};


class Dset {
public:
    /*
    path compression and union by size
    */
    Dset(int size): parent(size), rank(size) {
        for(int i=0; i<size; ++i) {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    
    int find(int u) {
        if (parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }
    
    bool merge(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        
        if (pu == pv) return false;
        
        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
            rank[pv] += rank[pu];
        } else {
            parent[pv] = pu;
            rank[pu] + rank[pv];
        } 
        
        return true;
    }
private:
    vector<int> parent;
    vector<int> rank;
};

class Solution {
public:
    
    // KRUSHKALS ALGORITHM - Minimum spanning tree
    int minCostConnectPointsKrushkals(vector<vector<int>>& points) {        
        int totalCost = 0;
        vector<Edge> edges;
        
        for (int i=0; i<points.size(); ++i) {
            for (int j=i+1; j<points.size(); ++j) {
                int cost = abs(points[j][0] - points[i][0]) + abs(points[j][1] - points[i][1]);
                Edge edge(i, j, cost);
                edges.push_back(edge);
            }
        }
        
        priority_queue<Edge, vector<Edge>, cmp> pq;
        
        for(auto &edge: edges) {
            pq.push(edge);
        }
        
        Dset dset(points.size());
        int remEdge = points.size()-1;
        while(!pq.empty() && remEdge > 0) {
            Edge edge = pq.top(); pq.pop();
            if (dset.merge(edge.node1, edge.node2)) {
                totalCost += edge.cost;
                remEdge -= 1;
            }
        }
        
        return totalCost;
    }

    // PRIMS ALGORITHM - minimum spanning tree
    int minCostConnectPoints(vector<vector<int>>& points) {        
        int totalCost = 0;
        int size = points.size();
        
        priority_queue<Edge, vector<Edge>, cmp> pq;
        vector<bool> visited(size, false);
        
        // Selecting point 0
        for (int i=1; i<size; ++i) {
            int cost = abs(points[i][0] - points[0][0]) + abs(points[i][1] - points[0][1]);
            pq.push({Edge(0,i,cost)});
        }
        visited[0] = true;
        
        int remEdge = size-1;
        while(!pq.empty() && remEdge > 0) {
            Edge edge = pq.top(); pq.pop();
            int node1 = edge.node1;
            int node2 = edge.node2;
            int cost = edge.cost;
            
            if(!visited[node2]) {
                totalCost += cost;
                visited[node2] = true;
                remEdge--;
                
                for(int i=0; i<size; ++i) {
                    if (!visited[i]) {
                        int cost = abs(points[node2][0] - points[i][0]) + abs(points[node2][1] - points[i][1]);
                        pq.push(Edge(node2, i, cost));
                    }
                }
            }
        }
        
        return totalCost;
    }
};


// PRIMS Algorithm (from other users)
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> visited(n, false);
        vector<int> min_dists(n, INT_MAX);
        
        int ans = 0;
        int curr_point = 0; // start with some point
        visited[0] = true;
        int remaining = n - 1;
        
        while (remaining > 0) {
            int x1 = points[curr_point][0];
            int y1 = points[curr_point][1];
            // find min distance for frontier
            // choose next point with min edge weight (closest point) to add to MST
            int min_dist = INT_MAX;
            for (int i = 0; i < n; ++i) {
                if (!visited[i]) {
                    int x2 = points[i][0];
                    int y2 = points[i][1];
                    
                    int dist = abs(x2 - x1) + abs(y2 - y1);
                    
                    min_dists[i] = min(min_dists[i], dist);
                    
                    if (min_dist > min_dists[i]) {
                        min_dist = min_dists[i];
                        curr_point = i;
                    }
                }
            }
            
            visited[curr_point] = true;
            ans += min_dist;
            remaining--;
        }
        
        return ans;
    }
};