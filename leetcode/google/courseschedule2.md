```c++
// Topological Sorting by indegree
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, vector<int>> adjList;
        map<int, int> indegree;
        queue<int> tSort;
        vector<int> res;

        // Initialize
        for (int i=0; i<numCourses; i++) {indegree[i] = 0;}
        
        // Populate adjacency list
        for (auto &courses: prerequisites) {
            adjList[courses[1]].push_back(courses[0]);
            indegree[courses[0]]++;
        }

        // Initialize queue with elements of indegree 0
        for (auto  &course: indegree) {
            if (course.second == 0) { 
                tSort.push(course.first);
            }
        }
        
        // process all elements continuously
        while (!tSort.empty()) {
            int node = tSort.front(); tSort.pop();
            res.push_back(node);
            
            if (adjList.find(node) != adjList.end()) {
                for (auto &nbr: adjList[node]) {
                    indegree[nbr]--;
                    if (indegree[nbr] == 0) {
                        tSort.push(nbr);
                    }
                }    
            }
            
        }
        
        return (res.size() == numCourses)? res: vector<int>();
   }
};
```

```c++  
// O(V+E) Graph and Stack Topological Sorting
#define VISITED 0x01
#define NOT_VISITED 0x02
#define PUSHED 0x03

class Solution {
public:
    map <int, vector<int>> adjList;
    stack <int> tSort; //topological sorted stack
    vector<int> res;
    map <int, int> seen;
    bool isPossible = true;
    
    void dfs(int course) {
        if (!isPossible) return;
        seen[course] = VISITED;
        for (auto &nbr: adjList[course]) {
            if (seen[nbr] == NOT_VISITED) {
                dfs(nbr);
            }
            else if (seen[nbr] == VISITED) {
                isPossible = false;
            }
        }
        seen[course] = PUSHED;
        tSort.push(course);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        for (auto &courses: prerequisites) {
            adjList[courses[1]].push_back(courses[0]);
        }
        
        for (int i=0; i<numCourses; i++) seen[i] = NOT_VISITED;

        for (int i=0; i<numCourses; i++) {
            if (seen[i] == NOT_VISITED) {
                dfs(i);
            }
        }
        
        if (!isPossible) return res;

        while(!tSort.empty()) {
            res.push_back(tSort.top()); tSort.pop();
        }
        return res;
    }
};


```