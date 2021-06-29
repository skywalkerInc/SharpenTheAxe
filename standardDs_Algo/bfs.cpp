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

};

class Bfs: public Graph{
public:
    void bfs(map<int, vector<int>> &adj, int startNode) {
        map<int, bool> visited;
        for (auto &edges: adj) {
            visited[edges.first] = false;
            for (auto &nbr: edges.second) {
                visited[nbr] = false;
            }
        }

        queue <int> que;
        que.push(startNode);
        visited[startNode] = true;

        while (!que.empty()) {
            int node = que.front(); que.pop();
            cout << node << " " << endl;
            for (auto &nbr: adj[node]) {
                if (!visited[nbr]) {
                    que.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
    }
};


int main() {
    Bfs bfs = Bfs();
    map<int, vector<int>> adj = bfs.getAdjListMap();
    bfs.printAdjList(adj);
    bfs.bfs(adj, 1);
    cout << "\nmain execution complete" << endl;
    return 0;
}

