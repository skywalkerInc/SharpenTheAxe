```c++
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<vector<double>> workers;
        for (int i=0;i<quality.size(); ++i) {
            workers.push_back({(double)(wage[i])/quality[i], (double)(quality[i])});
        }
        sort(workers.begin(), workers.end());
        
        priority_queue<int> pq; //for quality
        double res=DBL_MAX, sumQuality=0;
        
        for(auto &worker: workers) {
            
            sumQuality += worker[1], pq.push(worker[1]);
            
            if (pq.size() > k)  sumQuality -= pq.top(), pq.pop();
            if (pq.size() == k) res = min(res, sumQuality*worker[0]);
        }
        
        return res;
    }
};



```