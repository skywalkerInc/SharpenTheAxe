```c++
class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> odd(n,0), even(n,0);
        odd[n-1] = even[n-1] = 1;
        
        map<int, int> arrMap;
        arrMap[arr[n-1]] = n-1;
        
        int res = 1;
        
        for (int i=n-2; i>=0; i--) {
            auto oddJump = arrMap.lower_bound(arr[i]); //hi
            auto evenJump = arrMap.upper_bound(arr[i]); //lo
            
            //if i is the odd jump
            if (oddJump != arrMap.end()) odd[i] = even[oddJump->second];
            if (evenJump != arrMap.begin()) even[i] = odd[(--evenJump)->second];
            
            
            if (odd[i]) res++;
            
            arrMap[arr[i]] = i;
        }
        
        return res;
    }
};

/*
odd-numbered-jumps: a[i] <= a[j], a[j] is smallest value : lower_bound: hi
even-numered-jumps: a[i] >= a[j], a[j] is largest value : upper_bound :lo

10,13,12,14,15
0  1   2  3  4

vector<int> even, odd;
indexMap: val: index  (-1)
upper and lower bounds

even [0,0,0,0,1] :upper bound 
odd  [0,0,0,1,1] :lower bound 

arrMap
val:index
15: 4





*/

```