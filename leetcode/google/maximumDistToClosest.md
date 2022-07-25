```c++
class Solution {
public:
    // [1,0,0,0,1,0,1]
    // l:0 r:1
    // md: 1
    int maxDistToClosest(vector<int>& seats) {
        int maxDist = 1;
        int l = -1;
        int r = 0;
        while (r < seats.size()) {
            if (l==-1) maxDist = max(maxDist, r);
            else if (r==seats.size()-1 && !seats[r]) maxDist = max(maxDist, r-l);
            else maxDist = max(maxDist, (r-l)/2);
            
            if (seats[r]) {
                l = r;
            }
            r++;
        }
        
        return maxDist;
    }
};

/*
[1,0,0,0,1,0,1]
[1,0,0,0]
[0,1]
[0,0,0,1,0,0,0,0]
*/
```