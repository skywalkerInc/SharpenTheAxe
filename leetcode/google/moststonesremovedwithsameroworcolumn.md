```c++
class Dset {
public:
    vector<int> parent;
    Dset(int size): parent{vector<int>(size)} {
        for(int i=0;i<size;i++) {
            parent[i] = i;
        }
    }
    
    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        } 
        return parent[u];
    }
    
    void merge(int u, int v) {
        parent[find(u)] = find(v);
    }
    
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        Dset dset = Dset(stones.size());
        for (int i=0; i<stones.size(); i++) {
            for(int j=0; j<i; j++) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    dset.merge(i, j);
                }
            }
        }
        
        int res = 0;
        for (int i=0; i<stones.size(); i++) {
            if (dset.find(i) == i) res++;
        }
        return stones.size() - res;
    }
};
```