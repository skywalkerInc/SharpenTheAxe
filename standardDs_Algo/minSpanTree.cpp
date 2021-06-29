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

class Dset {
public:
    vector<int> parent;
    vector<int> rank;
    Dset(int size): parent{vector<int>(size+1, -1)}, rank{vector<int>(size+1, 0)} {}
    int find(int u) {
        if (parent[u] < 0) return u;
        else return parent[u] = find(parent[u]);
    }
    bool merge(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv) return false;
        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu++];
        }
        return true;
    }
};

class MinSpanTree : public Graph {
public:
    

    map<int, vector<int>> kruskals(map<int, vector<pair<int, int>>> &adj) {
        vector<vector<int>> ans;
        
        set<int> nodes;
        map<int, int> nodeMap;
        
        vector<vector<int>> edgeList; // [[u, v, w], ...]
        for (auto &edges: adj) {
            int u = edges.first;
            nodes.insert(u);
            for (auto &nbr: edges.second) {
                int v = nbr.first;
                int w = nbr.second;
                edgeList.push_back({u, v, w});
                nodes.insert(v);
            }
        }
        int index = 0;
        for (auto &node: nodes) {
            nodeMap[node] = index++;
        }

        sort(edgeList.begin(), edgeList.end(), [](const vector<int> a, const vector<int> b){
            return a[2] < b[2];
        });

        Dset dset(nodes.size());
        for(auto &edge: edgeList) {
            cout << edge[0] << " : " << edge[1] << endl;
            if (dset.merge(nodeMap[edge[0]], nodeMap[edge[1]])) {
                ans.push_back(edge);
            }
        }

        map<int, vector<int>> ret;
        for (auto &edge: ans) {
            ret[edge[0]].push_back(edge[1]);
        }

        return ret;

    }
};

int main() {
    MinSpanTree minSpanTree = MinSpanTree();
    map<int, vector<pair<int, int>>> wAdj = minSpanTree.getWeightedAdjList();
    minSpanTree.printWeightedAdjList(wAdj);
    

    // shortestPath.djkshatra(adj, 1);
    // dist = shortestPath.djkshatra(wAdj,1);
    // shortestPath.printDist(dist);

    map<int, vector<int>> retAdj = minSpanTree.kruskals(wAdj);
    minSpanTree.printAdjList(retAdj);

    cout << "\nmain execution complete" << endl;
    return 0;
}

