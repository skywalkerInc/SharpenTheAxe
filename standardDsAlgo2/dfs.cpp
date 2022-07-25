#include <bits/stdc++.h>
using namespace std;

/*
Used for:
1. traversing the graph
2. traversing from one node to other node 

1. Traversing the graph once:
TimeComplexity: O(V + E)
SpaceComplexity: O(V) (for stack)

2. Traversing through all possible paths from node a to node b
TimeComplexity: O((V-1)!)
SpaceComplexity: O(V3) (for stack)
*/

/*
stack apis:
stack.push()
stack.top()
stack.pop()


set.insert()
set.erase(iter)

priority_queue<int> pq;
priority_queue<int, vector<int>, greater<int>>
pq.push_back()
pq.top()
pq.pop()

directed acclic graph does not need visited field! 
*/

class dfs {
public:
    dfs(int size, vector<vector<int>>& edges): visited(size), adjlist(vector<vector<int>>(size)) {
        fill(visited.begin(), visited.end(), false);
        for (auto &edge: edges) {
            adjlist[edge[0]].push_back(edge[1]);
            adjlist[edge[1]].push_back(edge[0]);
        }

    }

    void traverserec(int source) {
        visited[source] = true;

        for(auto &nbr: adjlist[srouce]) {
            if(!visited[nbr]) {
                dfs(adjlist, nbr);
            }
        }
    }

private:
    vector<bool> visited;
    vector<vector<int>> adjlist;
};


class dfs {
public:
    dfs(int n, vector<vector>>& edges): visited(n), adjlist(vector<vector<int>>(n)) {
        fill(visited.begin(), visited.end(), false);
        for(auto &edge: edges) {
            adjlist[edge[0]].push_back(edge[1]);
            adjlist[edge[1]].push_back(edge[0]);
        }
    }

    void traverseiter(int source) {
        
        st.push(source);

        while (!st.empty())
        {
            int node = st.top(); st.pop();
            visited[node] = true;

            for(auto &nbr: adjlist[node]) {
                if(!visited[nbr]) {
                    st.push[nbr]
                }
            }
        }
        
        
    }
private:
    vector<int> visited;
    vector<vector<int>> adjlist;
    stack<int> st;
};









int n = 10; //number of nodes
vector<bool> visited(n, false);
void dfs(vector<vector<int>>& adjList, int source) {
    visited[source] = true;

    for(auto &node: adjList[source]) {
        if (!visited[node]) {
            dfs(adjList, node);
        }
    }
}

int n = 10;
stack<int> st;
vector<bool> visited(n, false);
void dfsstack(vector<vector<int>>& adjList, int source) {
    
    st.push(source);

    while(!st.empty()) {
        
        int node = st.top(); st.pop();
        visited[node] = true;

        for (auto &nbr: adjList[node]) {
            st.push(nbr);
        }
    }
    
}