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

class TopologicalSort : public Graph {
public:
    stack<int> st;
    map<int,bool> visited;

    void tSortUtil(map<int, vector<int>> &adj, int node) {
        visited[node] = true;

        for (auto &nbr: adj[node]) {
            if (!visited[nbr]) {
                tSortUtil(adj, nbr);
            }
        }

        st.push(node);
    }

    vector<int> topologicalSort(map<int, vector<int>> &adj) {
        set<int> nodes;
        for (auto &edge: adj) {
            visited[edge.first] = false;
            nodes.insert(edge.first);
            for (auto &nbr: edge.second) {
                visited[nbr] = false;
                nodes.insert(nbr);
            }
        }

        for (auto &node: nodes) {
            if (!visited[node]) {
                tSortUtil(adj, node);
            }
        }

    }

};

int main() {

}