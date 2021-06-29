```c++ Graph
class Solution {
public:
    void dfs(map <string, vector<string>> &adjList, string node, map<string,bool> &seen, vector<string> &output)
    {
        cout << "dfs: " << node << " " << seen[node] << endl;
        if (!seen[node] ) 
        {
            
            output.push_back(node);
            seen[node] = true;
            for (auto &obj: adjList[node])
            {
                dfs(adjList, obj, seen, output);
            }

        }
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector <vector <string>> ret;

        // Create a forest from accounts (adjacency list)
        map <string, vector <string>> adjList;
        map <string, string> emailToUser;
        
        for (auto &acc: accounts)
        {
            string user = acc[0];
            //acc: [u, e1, e2, e3]
            for (int i = 1; i < acc.size(); i++) 
            {
                string email = acc[i];
                adjList[email].push_back(acc[1]);
                adjList[acc[1]].push_back(email);
                emailToUser[email] = user;
            }
        } 

        map <string, bool> seen;
        for (auto &ele: adjList) 
        {
            seen[ele.first] = false;
        }
        
        for (auto &ele: adjList) 
        {
            cout << "start: ";   
            for (auto &node: ele.second)
            {
                cout << node << " ";
            }
            cout << endl;
        }

        for (auto &ele: adjList)
        {
            if (seen[ele.first])
            {
                continue;
            }
            //cout << "base: " << ele.first << endl;
            vector <string> temp;
            temp.push_back(emailToUser[ele.first]);
            dfs(adjList, ele.first, seen,temp);
            sort(temp.begin() + 1, temp.end());
            
            ret.push_back(temp);
        }
            
        return ret;
    }
};

/*
e1: u1
e2: u1
e3: u1
e4: u2
e5: u2
e6: u3

email: user
[[e1,e2,e3],[e4, e5], [e6, e2]]
res: [[e1,e2,e3,e6], [e4,e5]]


[e1,e1,e1, e4, e4, e6, e6]

union(x,y):
    arr[find(x)] = find(y)
    
find(x):
    if arr[x] == x:
        return x
    return find(arr[x])

loop acc
    loop email
        if email not in map
            add to map
        add to list
        union(email[0], email)
        
        

*/
```


```c++ Set

class DisJointSet {
public:
    vector <int> parent;
    vector <int> depth;
    DisJointSet(int size): parent{vector<int>(size)}, depth{vector<int>(size, 0)} {
        for (int i=0; i<size; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x) {
            return x;
        }else {
            return parent[x] = find(parent[x]);
        }
    }
    void merge(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;
        if (depth[px] < depth[py]) {
            parent[px] = py;
        } else if (depth[py] < depth[px]) {
            parent[py] = px;
        } else {
            parent[px] = py;
            depth[py]++;
        }
    }
    
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        map <string, int> emailIndexMap;
        map <int, string> indexUserMap;
        int emailIndex =  0;
        for (auto & emails: accounts) {
            for (int i=1; i < emails.size(); i++) {
                if (!emailIndexMap.count(emails[i])) {
                    emailIndexMap[emails[i]] = emailIndex;
                    indexUserMap[emailIndex] = emails.front();
                    emailIndex++;
                }
            }
        }

        DisJointSet emailSet(emailIndexMap.size());
        for (auto & emails: accounts) {
            for (int i=2; i<emails.size(); i++) {
                emailSet.merge(emailIndexMap[emails[1]], emailIndexMap[emails[i]]);
            }
        }
        
        map <int, vector<string>> ans;
        for (auto & email: emailIndexMap) {
            int index = emailSet.find(email.second);
            if (ans[index].empty()) {
                ans[index].push_back(indexUserMap[index]);
            }
            ans[index].push_back(email.first);
        }
        
        vector<vector<string>> res;
        for (auto & account : ans) { 
            res.push_back(account.second);
        }
        
        return res;
    }

};

```

## Solved by brute force first
## did not understood union set solution
## Graph Solution 
``` py
class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        emailUserDict = {}
        graph = collections.defaultdict(set)
        
        for acc in accounts:
            user = acc[0]
            for email in acc[1:]:
                emailUserDict[email] = user
                graph[email].add(acc[1])
                graph[acc[1]].add(email)
        
        # Depth First Search for connected emails
        ans = []
        seen = set()
        
        for email in graph:
            if email not in seen:
                seen.add(email)
                
                stack = [email]
                emailgroup = [email]
                
                while stack:
                    node = stack.pop()
                    
                    for nei in graph[node]:
                        if nei not in seen:
                            seen.add(nei)
                            emailgroup.append(nei)
                            stack.append(nei)
                
                ans.append([emailUserDict[email]] + sorted(emailgroup))
        return ans
                            
        
```

