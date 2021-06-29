#include <bits/stdc++.h>
using namespace std;

class Sort {
public:
    Sort() {}
};

class HeapSort: public Sort {
public:
    void heapify(vector<int> &nums, int root_index, int size) {
        int imax = root_index;
        int il = 2*root_index +1;
        int ir = 2*root_index +2;
        if (il < size && nums[il] > nums[imax]) imax = il;
        if (ir < size && nums[ir] > nums[imax]) imax = ir;
        if (imax != root_index) {
            swap(nums[imax], nums[root_index]);
            heapify(nums, imax, size);
        }
    }
    void sort(vector<int> &nums) {
        for (int i=nums.size()/2; i>=0; i--) {
            heapify(nums, i, nums.size());
        }

        for(int i=nums.size()-1; i>0; i--) {
            swap(nums[0], nums[i]);
            heapify(nums, 0,i);
        }
    }
};

int main() {
    vector<int> nums = {3,2,7,1,9};
    HeapSort sort = HeapSort();
    sort.sort(nums);
    for (auto &num:nums) cout << num << endl;
}


