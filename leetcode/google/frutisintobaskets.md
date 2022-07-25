```c++
class Solution {
public:
    //[1,2,3,2,2]
    //res = 2
    //l=0, r=0, map: 1:0, 2:1, 3:2
    int totalFruit(vector<int>& fruits) {
        int l=0;
        map<int, int> typeCount;
        int res = 0;
        
        for (int i=0; i<fruits.size(); i++) {
            typeCount[fruits[i]]++;
            
            if (typeCount.size()>2) {
               if((--typeCount[fruits[l]]) == 0) typeCount.erase(fruits[l]);
                l++;
            }
            
            res = max(res, i-l+1);
        }
        
        return res;
    }
};

/*
[1,2,3,2,2]

latest index of each number
type: index
typeCount =0;
left, right

if typeCount > 2 reset left to min of map index

max(right-left, maxfruit)


*/
```