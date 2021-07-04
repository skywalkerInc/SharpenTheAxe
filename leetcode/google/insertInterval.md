```c++
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
         
        int newStart = newInterval[0];
        int newEnd =  newInterval[1];
        
        // Add any interval before newStart
        int curr = 0;
        while (curr<intervals.size() && newStart > intervals[curr][0]) {
            res.push_back(intervals[curr]);
            curr++;
        }
        
        vector<int> updatedInterval = {newStart, newEnd};
        
        // Check if interval is overlapping with curent one
        if (res.empty() || res.back()[1] < newStart) {
            res.push_back(newInterval);
        }
        else
        {
            res.back()[1] = fmax(newEnd, res.back()[1]);
        }
        
        //merge next intervals if needed
        while (curr < intervals.size())
        {
            if (intervals[curr][0] > newEnd) {
                res.push_back(intervals[curr]);
            }
            else
            {
                res.back()[1] = fmax(intervals[curr][1], res.back()[1]);
            }
            
            curr++;
        }
        
        return res;
    }
};
```