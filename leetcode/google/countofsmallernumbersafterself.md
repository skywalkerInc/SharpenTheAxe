
```c++ modified merge sort
class MergeSort {
    vector<int> indices;
public:
    MergeSort(vector<int>& nums): indices{vector<int>(nums.size())} {
        for (int i=0; i<nums.size(); i++) {
            indices[i] = i;
        }
    }
    
    void merge(int left, int right, int mid, vector<int>& nums, vector<int>& res) {
        int i=left; //left array start
        int j=mid; //right array start
        
        vector<int> temp;
        while (i < mid && j < right) {
            if (nums[indices[i]] <= nums[indices[j]]) {
                res[indices[i]] += j-mid;
                temp.push_back(indices[i]);
                i++;
            } else {
                temp.push_back(indices[j]);
                j++;
            }
        }
        
        while (i < mid) {
            res[indices[i]] += j-mid;
            temp.push_back(indices[i]);
            i++;
        }
        
        while (j < right) {
            temp.push_back(indices[j]);
            j++;
        }
        
        move(temp.begin(), temp.end(), indices.begin() + left);
    }
    
    void mergeSort(vector<int>& nums, int left, int right, vector<int>& res) {
        if (right - left <= 1) return;
        
        int mid = (left + right) /2;
        mergeSort(nums, left, mid, res);
        mergeSort(nums, mid, right, res);
        merge(left, right, mid, nums, res);
    }
    

};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int size = nums.size();
        vector<int> res(size, 0);
        MergeSort ms = MergeSort(nums);
        ms.mergeSort(nums, 0, size, res);
        return res;
    }
};
```

```c++ BITree


class BIT {
    vector<int> biTree;
public:
    BIT(int size): biTree{vector<int>(size+1, 0)} {
    }
    
    int getCount(int index) {
        int count = 0;
        while (index > 0) {
            count += biTree[index];
            index -= index & (-index);
        }
        return count;
    }
    
    void update(int index, int value) {
        index += 1;
        while (index < biTree.size()) {
            biTree[index] += value;
            index += index & (-index);
        }
    }
    
    // index += index & (-index) update
    // index -= index & (-index) get
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int offset = 1e4;
        int size = 2*1e4 + 1;
        
        BIT biTree = BIT(size);
        
        vector<int> counts;
        for (int i=nums.size()-1; i>=0; i--) {
            int smallCount = biTree.getCount(nums[i] + offset);
            counts.push_back(smallCount);
            biTree.update(nums[i] + offset, 1);
        }
        
        reverse(counts.begin(), counts.end());
        return counts;
    }
};
```