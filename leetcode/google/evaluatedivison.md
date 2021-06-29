```c++ O((M+N)log(N))
class Dsu {
public:
    vector<int> parent;
    vector<double> weight;
    Dsu(): parent{vector<int>(40)}, weight{vector<double>(40, 1.0)} {
        for (int i=0; i<40; i++) {
            parent[i] = i;
        }
    }
    
    pair<int, double> find(int u ) { //0 // 1 //2

        if (parent[u] != u) {
            pair<int, double> res = find(parent[u]);
            parent[u] = res.first;
            weight[u] = weight[u] * res.second;
        }
        
        return {parent[u], weight[u]};
    }
    
    void merge(int u, int v, double q) {
        pair<int, double> pu = find(u);
        pair<int, double> pv = find(v);
        if (pu.first != pv.first) {
            parent[pu.first] = pv.first;
            weight[pu.first] = q * (pv.second / pu.second);    
        }
    } 
};

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries)     {
        Dsu dsu = Dsu();
        map<string, int> numIndexMap;
        int numIndex = 0;
        for (int i=0; i<equations.size(); i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            double q = values[i];
            if (!numIndexMap.count(u)) numIndexMap[u] = numIndex++;
            if (!numIndexMap.count(v)) numIndexMap[v] = numIndex++;
            dsu.merge(numIndexMap[u], numIndexMap[v], q);
        }
        
        vector<double> res(queries.size(), -1.0);
        for (int i=0; i<queries.size(); i++) {
            if (!(numIndexMap.count(queries[i][0])) || !(numIndexMap.count(queries[i][1]))) continue;
            
            pair<int, double> pwu = dsu.find(numIndexMap[queries[i][0]]);
            pair<int, double> pwv = dsu.find(numIndexMap[queries[i][1]]);
            if (pwu.first != pwv.first) continue;
            
            res[i] = pwu.second / pwv.second;
        }
        
        return res;
    }
};

/*
[[a,b], [b,c]]
[i1, i2]
[a,c]

map: node to index


initial
[-1,-1,-1]
[1,1,1]

after union
[1,2,-1]
[2,3,1]

after find
[2,2,-1]
[6,3,1]

a->b->c

b->c
a->c
*/


/*

a

*/
```