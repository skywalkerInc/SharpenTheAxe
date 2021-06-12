## 25min
``` c++
#include <queue>
#include <bits/stdc++.h>

bool comparator(vector<int> interval1, vector<int> interval2) {
    return interval1[0] < interval2[0];
}

class Solution {
public:
    priority_queue<int> endTime;
    
    int minMeetingRooms(vector<vector<int>>& intervals) {
        
        int ret = 0;
        
        //sort intervals based on start time        
        sort(intervals.begin(), intervals.end(), comparator);
        
        for(int i=0; i<intervals.size(); i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            
            
            if (!endTime.empty()) {
                // printf("top: %d, s: %d, e: %d\n", -1*endTime.top(), start, end);
                if (start < -1*endTime.top()) {
                    endTime.push(-1*end);
                }
                else
                {
                    endTime.pop();
                    endTime.push(-1*end);
                }
            }
            else
            {
                // printf("s: %d, e: %d\n",  start, end);
                endTime.push(-1*end);
            }
            
            ret = fmax(ret, endTime.size());
        }
        
        return ret;
    }
};
```