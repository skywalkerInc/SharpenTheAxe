#include <bits/stdc++.h>
using namespace std;

/*
Used for:
-> Traversing all vertices in the “graph”;
-> Finding the shortest path between two vertices in a graph where all edges have equal and positive weights. (unweighted graph)

queue<int> que;
que.push()
que.pop()
que.front()
que.back();
*/



class Bfs {
public:
    Bfs(vector<vector<int>>& edges) {
        
    }

    void traverse(int source) {
        queue<int> que;
        que.push(source);
        visited[source] = true;

        while(!que.empty()) {
            int node = que.front(); que.pop();
            for (auto &nbr: adjlist[node]) {
                if (!visited[nbr]) {
                    visited[nbr] = true;
                    que.push(nbr);
                }
            }
        }
    }

    void levelordertraverse(int source) {
        queue<int> que;
        que.push(source);
        visited[source] = true;

        vector<vector<int>> levelorder;

        while(!que.empty()) {
            int size = que.size();
            levelorder.push_back({});

            for (int i=0; i<size; ++i) {
                int node = que.front(); que.pop();
                levelorder.back().push_back(node);

                for (auto &nbr: adjlist[node]) {
                    if (!visited[node]) {
                        visited[node] = true;
                        que.push(nbr);
                    }
                }
            }
        }
    }
private:
    unordered_map<int, vector<int>> adjlist;
    vector<bool> visited;
}