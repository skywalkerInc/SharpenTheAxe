#include <bits/stdc++.h>
using namespace std;

/*
Commonly used: path compression with union by size with parent and rank array
Time Complexity:
Union-find constructor: O(N)
find: O(logN) , best case O(1), for consecutive find it will be O(1) due to path compression, worst case O(N) when graph is skewed!
union: O(logN) depends on find operation, average is O(logN)
connected: O(logN)
*/

// Quick find
/*
constructor: O(N)
find : O(1)
union: O(N)
Connected: O(1)
*/
class Dset {
public:
    Dset(int size) : parent(size) {
        for (int i = 0; i <size; ++i) {
            parent[i] = i;            
        }
    }

    int find(int u) {
        return parent[u];
    }

    int merge(int u, int v) {
        int parentu = find(u);
        int parentv = find(v);
        if (parentu != parentv) {
            for (int i=0; i<parent.size(); ++i) {
                if (parent[i] == parentv) {
                    parent[i] = parentu;
                }
            }
        }
    }
private:
    vector<int> parent;
};


// Quick union
/*
constructor: O(N)
find : O(N)
union: O(N)
Connected: O(N)
*/
class Dset {
public:
    Dset(int size) : parent(size) {
        for (int i=0; i<size; ++i) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (parent[u] == u) {
            return u;
        }
        return find(parent[u]);
    }

    int merge(int u, int v) {
        int parentu = find(u);
        int parentv = find(v);
        if (parentu != parentv) {
            parent[parentv] = parentu;
        }
    }

private:
    vector<int> parent;
};

// Union by rank (height of tree)
/*
constructor: O(N)
find : O(logN)
union: O(logN)
Connected: O(logN)
*/
class Dset {
public:
    Dset(int size) : parent(size), rank(size) {
        for(int i=0; i<size; ++i) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int find(int u) {
        if (parent[u] == u) {
            return u;
        }
        return find(parent[u]);
    }

    int merge(int u, int v) {
        int parentu = find(u);
        int parentv = find(v);
        if (parentu != parentv) {
            if (rank[u] < rank[v]) {
                parent[parentu] = parentv;
            } else if (rank[u] > rank[v]) {
                parent[parentv] = parentu;
            } else {
                parent[parentv] = parentu;
                rank[parentu] += 1;
            }
        }
    }
private: 
    vector<int> parent;
    vector<int> rank;

};

// path compression (can go with quick union or rank by size (not union by height))
/*
constructor: O(N)
find : O(logN) for first time and then O(1) for consecutive find, worst case O(N)
union: O(logN) best case O(1), worst case O(N)
Connected: O(1)
*/
class Dset {
public:
    Dset(int size) : parent(size) {
        for (int i=0; i<size; ++i) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (parent[u] == u) {
            return u;
        }
        return parent[u] = find(u);
    }

    void merge(int u, int v) {
        int parentu = find(u);
        int parentv = find(v);
        if (parentu != parentv) {
            parent[parentv] = parentu;
        }
    }
private:
    vector<int> parent;
};

// TODO: union by rank with single array
class Dset {
public:
    Dset(int size) : parent(size) {
        for (int i=0; i<size; ++i) {
            parent[i] = -1; //each node is at top and with size 1
        }
    }

    int find(int u) {
        if (parent[u] < 0) { return u; }
        return find(parent[u]);
        
    }

    void mergebysize(int u, int v) {
        int pu = find(u); // parent[pu] will be negative
        int pv = find(v); // parent[pv] will be negative

        if (pu != pv) {
            if (parent[pu] < parent[pv]) {
                parent[pu] += parent[pv];
                parent[pv] = pu;
            } else{
                parent[pv] += parent[pu];
                parent[pu] = pv;
            }
        }
    }

    void mergebyheight(int u, int v) {
        int pu = find(u); // parent[pu] will be negative
        int pv = find(v); // parent[pv] will be negative
        
        if (parent[pu] < parent[pv]) {
            parent[pv] = pu;
        } else if (parent[pu] > parent[pv]) {
            parent[pu] = pv;
        } else {
            parent[pv] = pu;
            parent[pu] -= 1;
        }
    }

private:
    vector<int> parent; // top of chain will be negative number whose abs value will be size/height, positive values will be parents
};



// Island problem
class Dset {
public:
    Dset(int size): parent(size), rank(size), count(size) {
        for (int i=0; i<size; ++i) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int find(int u) {
        if (parent[u] == u)  {
            return u;
        }
        return parent[u] = find(u);
    }

    void merge(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu != pv) {
            parent[pv] = pu;
            count--;
        }
    }

    int getCount() {
        return count;
    }

private:
    vector<int> parent;
    vector<int> rank;
    int count;
};

int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    if (n == 0) return 0;
    
    Dset dset(n);
    for(int i=0; i<n; ++i) {
        for (int j=0; j<n;++j) {
            if (isConnected[i][j]) {
                dset.merge(i, j);
            }
        }
    }

    return dset.getCount();
}