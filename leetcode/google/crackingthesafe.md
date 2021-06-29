```c++
class Solution {
public:
    string crackSafe(int n, int k) {
        string ans = string(n, '0');
        set<string> visited;
        visited.insert(ans);
        
        for (int i=0; i<pow(k, n); i++) {
            string prev = ans.substr(ans.size() - (n-1), n-1);
            for (int j=k-1; j>=0; j--) {
                string now = prev + to_string(j);
                if (!visited.count(now)) {
                    visited.insert(now);
                    ans += to_string(j);
                    break;
                }
            }
        }
        
        return ans;
    }
};

```

```c++
class Solution {
    int n, k, v;
    vector<vector<bool>> visited;
    string res;
public:
    string crackSafe(int n, int k) {
        if (k==1) return string(n, '0');
        this->n = n;
        this->k = k;
        v = 1;
        for (int i = 0; i < n -1; ++i) v *= k;
        visited.resize(v, vector<bool>(k, false));
        dfs(0);
        return res + res.substr(0, n-1);
    }
    
    void dfs(int u) {
        for (int i=0; i<k;i++) {
            if (!visited[u][i]) {
                visited[u][i] = true;
                dfs((u*k + i) % v);
                res.push_back('0' + i);
            }
        }
    }
    
};


```