```c++
class Comp {
    vector<int> param;
public:
    Comp(vector<int> p): param(p) {}
    
    bool operator()(int a, int b) {
        return param[a] < param[b];
    }
};

class Solution {
public:
    /*
    "abcd"
    i: [0, 2]
    s: ["a", "cd"]
    t: ["eee", "ffff"]
    
    res = eeebffff
    */
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        string res;
        int n = indices.size();
        
        vector<int> indexes(n, 0);
        for (int i=0; i<n; i++) indexes[i] = i;
        
        sort(indexes.begin(), indexes.end(), Comp(indices));
        
        int nextIndex = 0; //4
        for(auto &i: indexes) {
            int index = indices[i]; //value of indices, i: index //2
            
            printf("i:%d, index:%d, ni:%d\n", i,index, nextIndex);
            if (nextIndex != index) {
                res += s.substr(nextIndex, index-nextIndex);
                nextIndex = index;
            }
            
            if (s.substr(index, sources[i].size()) == sources[i]) {
                res += targets[i];
                nextIndex += sources[i].size();
            }
            
            
        }
        
        if (nextIndex < s.size()) {
            res += s.substr(nextIndex, s.size()-nextIndex);
        }
        
        return res;
    }
};


//abcd -> ab | cd -> eee | cd -> eeecd
//eeecd


```