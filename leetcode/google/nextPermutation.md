```c++
class Solution {
public:
    void reverse(vector<int>&nums, int start, int end) {
        //i=1, i<2 
        for (int i= start; i< (start + (end+1-start)/2 ); i++) {
            swap(nums[i], nums[end-(i-start)]); //end is inclusive
        }
    }
    
    // [1,3,2]
    //[2,3,1] s=1,e=2,i=1
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        int i=n-1;
        while (i>0 && nums[i] <= nums[i-1]) i--;
        
        if (i > 0) {
            int j = n-1;
            while(nums[j] <= nums[i-1]) j--;
            swap(nums[i-1], nums[j]);
        }
        reverse(nums, i, n-1);
    }
};

/*

[1,3,2]
swapCount

input: [1 5 4 3]
ans: [3 1 4 5]

123
132
213
231
312
321

1234
1243

1 _ 4 3

1324
1342
1423
1432
---
2134
2
...
4321

000
001
010
011
100

res

[1, 5, 4, 3]
[1, 5, 3, 4]

3 

1 4 

*/
```