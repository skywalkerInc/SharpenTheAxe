#include <bits/stdc++.h>
using namespace std;


class Graph {
public:
    vector<vector<int>> getAdjListVec() {
        
        vector<vector<int>> adj = {
            {1,2},
            {2,3},
            {3,4},
            {6,7}
        };
        
        return adj;
    }

    map<int, vector<int>> getAdjListMap() {
        map<int, vector<int>> adj = {
            {1, vector<int>{2,3}},
            {2, vector<int>{4,5}},
            {3, vector<int>{6}},
            {9, vector<int>{10}}
        };
        return adj;
    }

    map<int, vector<pair<int, int>>> getWeightedAdjList() {
        map<int, vector<pair<int, int>>> adj = {
            {1, vector<pair<int, int>>{{2,1}, {3,1}}},
            {2, vector<pair<int, int>>{{3,1}, {4,2}}},
            {3, vector<pair<int, int>>{{4,1}, {5,1}}},
            {5, vector<pair<int, int>>{{6,1}}}
        };
        return adj;
    }

    set <int> getNodes(vector<vector<int>> &adj) {
        set <int> nodes;
        for (auto &edge: adj) {
            nodes.insert(edge[0]);
            nodes.insert(edge[1]);
        }
        return nodes;
    }

    set <int> getNodes(map<int, vector<int>> &adj) {
        set <int> nodes;
        for (auto &edges: adj) {
            nodes.insert(edges.first);
            for (auto &nbr: edges.second) {
                nodes.insert(nbr);
            }
        }
        return nodes;
    }

    map <int, int> getNodeMap(vector<vector<int>> &adj) {
        int index = 0;
        map <int, int> nodeMap; // node:index
        for (auto &edge: adj) {
            if (!nodeMap.count(edge[0])) {
                nodeMap[edge[0]] = index++;
            }
            if (!nodeMap.count(edge[1])) {
                nodeMap[edge[0]] = index++;
            }
        }
        return nodeMap;
    }

    vector<vector<int>> getMappedAdjList(vector<vector<int>> &adj, map<int, int> &nodeMap) {
        vector<vector<int>> mappedAdj;
        for (auto &edge: adj) {
            mappedAdj.push_back(vector<int>{nodeMap[edge[0], edge[1]]});
        }
        return mappedAdj;
    }


    map<int, vector<int>> convertAdjListVecToMap(vector<vector<int>> &adjListVec) {
        map <int, vector<int>> adj;
        for (auto &edge: adjListVec) {
            adj[edge[0]].push_back(edge[1]);
        }
        return adj;
    }

    int getStartNode(map<int, vector<int>> &adjListMap) {
        return adjListMap.begin()->first;
    }

    int getStartNode(vector<vector<int>> &adj) {
        return adj[0][0];
    }

    void printAdjList(map<int, vector<int>> &adj) {
        for (auto &edges: adj) {
            cout << edges.first << " : ";
            for (auto &nbr: edges.second) {
                cout << nbr << ", ";
            }
            cout << endl;
        }
    }

    void printWeightedAdjList(map<int, vector<pair<int, int>>> &wAdj) {
        for (auto &edges: wAdj) {
            cout << edges.first << " : ";
            for (auto &nbr: edges.second) {
                cout << "{" << nbr.first << ", " << nbr.second << "}, ";
            }
            cout << endl;
        }
    }

};

class ShortestPath: public Graph {
public:
    const int INF = (1<<30);
    // Return distance of each node from source
    map<int, int> djkshatra(map<int, vector<pair<int, int>>> &adj, int src) {
        map<int, int> dist;
        map<int, bool> visited;
        priority_queue <pair<int, int>> pq; //{dist, node}

        for(auto &edges: adj) {
            dist[edges.first] = this->INF;
            visited[edges.first] = false;
            for (auto &nbr: edges.second) {
                dist[nbr.first] = this->INF;
                visited[nbr.second] = this->INF;
            }
        }
        dist[src] = 0;

        pq.push({dist[src], src});
        while (!pq.empty()) {
            int u = pq.top().second; pq.pop();
            if (!visited[u]) {
                for (auto &nbr: adj[u]) {
                    int v = nbr.first;
                    int w = nbr.second;
                    if (dist[v] > dist[u] + w) {
                        dist[v] = dist[u] + w;
                        pq.push({dist[v], v});
                    }
                }
            }
        }
        
        return dist;

    }

    map<int, int> bellmanFord(map<int, vector<pair<int, int>>> &adj, int src) {
        map <int, int> dist;
        map <int, int> path;

        for (auto &edges: adj) {
            dist[edges.first] = this->INF;
            for (auto &nbr: edges.second) {
                dist[nbr.first] = this->INF;
            }
        }
        dist[src] = 0;

        for (int i=0; i<dist.size(); i++) {
            for (int j=0; j<adj[i].size(); j++) {
                int v = adj[i][j].first;
                int w = adj[i][j].second;
                if (dist[v] > dist[i] + w) {
                    dist[v] = dist[i] + w;
                    path[v] = i;
                }
            }
        }

        for (int i=0; i<adj.size(); i++) {
            for (int j=0; j<adj[i].size(); j++) {
                int v = adj[i][j].first;
                int w = adj[i][j].second;
                if (dist[v] > dist[i] + w) {
                    cout << "negative cycle found";
                    return dist;
                }
            }
        }
        
        return dist;
    }

    void printDist(map<int, int> dists) {
        for (auto &dist: dists) {
            cout << dist.first << " : " << dist.second << endl;
        }
    }
};

int main() {
    ShortestPath shortestPath = ShortestPath();
    map<int, vector<pair<int, int>>> wAdj = shortestPath.getWeightedAdjList();
    shortestPath.printWeightedAdjList(wAdj);
    map<int, int> dist;

    // shortestPath.djkshatra(adj, 1);
    // dist = shortestPath.djkshatra(wAdj,1);
    // shortestPath.printDist(dist);

    dist = shortestPath.bellmanFord(wAdj, 1);
    shortestPath.printDist(dist);

    cout << "\nmain execution complete" << endl;
    return 0;
}