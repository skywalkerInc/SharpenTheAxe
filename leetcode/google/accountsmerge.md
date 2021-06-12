


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

