## My Solution - TLE (use bidirectional bfs for no tle)
```
class Solution:
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
        wordList.append(beginWord)
        #wordList = list(set(wordList))
        # print(wordList)
        n = len(wordList)
        if n == 0:
            return 0
        wlen = len(wordList[0])
        start = n-1
        target = None #finding below
        
        #create a bidirectional array
        adjlist = defaultdict(list)
        vis = [0]*n
        
        for i in range(n-1):
            for j in range(i+1, n):
                count = 0
                for k in range(wlen):
                    if wordList[i][k] != wordList[j][k]:
                        count += 1
                        if count > 1:
                            break
                if count == 1:
                    adjlist[i].append(j)
                    adjlist[j].append(i)
        
        for i, word in enumerate(wordList):
            if word == endWord:
                target = i
        
        if target == None:
            return []
        q = deque()
        vis = [0]*n
        dist = [float('inf')]*n #distance from begin
        dist[-1] = 0
        q.append((n-1, 1))
        vis[n-1] = True
        
        # print(adjlist)
        
        def dfs(word_index):
            nonlocal dist
            nonlocal tmp
            nonlocal wordList
            nonlocal endWord
            nonlocal res
            nonlocal adjlist
            word = wordList[word_index]
            tmp.append(word)
            if word == endWord:
                res.append(list(tmp))
                tmp.pop()
                return 
            if word_index in adjlist:
                for nei in adjlist[word_index]:
                    if dist[nei] == dist[word_index]+1:
                        dfs(nei)
            tmp.pop()
        
        #do bfs to tag shortest path
        #find shortest path
        
        while q:
            out, depth = q.popleft()
            dist[out] = depth
            
            for nbr in adjlist[out]:    
                if not vis[nbr]:
                    vis[nbr] = True
                    q.append((nbr, depth+1))
        
        # print(dist)
        res = []
        tmp = []
        dfs(start)
        # print(res)
            
        return res
```

## leetcode discussion
```
class Solution(object):
    def findLadders(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: List[List[str]]
        """
        def dfs(word):
            tmp.append(word)
            if word == endWord:
                res.append(list(tmp))
                tmp.pop()
                return 
            if word in graph:
                for nei in graph[word]:
                    if dist[nei] == dist[word]+1:
                        dfs(nei)
            tmp.pop()

        wordSet = set(wordList)
        if endWord not in wordSet:
            return []
        alphabets = 'abcdefghijklmnopqrstuvwxyz'
        q = collections.deque([(beginWord, 0)])
        dist = {}
        graph = collections.defaultdict(set)
        seen = set([beginWord])
        while q:
            u, d = q.popleft()
            dist[u] = d
            for i in range(len(u)):
                for alph in alphabets:
                    if alph != u[i]:
                        new = u[:i]+alph+u[i+1:]
                        if new in wordSet:
                            graph[u].add(new)
                            graph[new].add(u)
                            if new not in seen:
                                q.append((new, d+1))
                                seen.add(new)
        if endWord not in dist:
            return []
        res = []
        tmp = []
        dfs(beginWord)
        return res 
```