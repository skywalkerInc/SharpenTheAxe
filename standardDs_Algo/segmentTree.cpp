#include <bits/stdc++.h>
using namespace std;

/*
    Use to find sum in given range of array
    It uses an array to keep sum of ranges and can be visualised as tree
*/
class SegmentTree {
public:
    vector<int> segTree;
    int arraySize;
    SegmentTree(vector<int>& arr) {
        arraySize = arr.size();
        int segTreeHeight = (int)(ceil(log2(arraySize)));
        int segTreeLen = 2*(int)pow(2, segTreeHeight) - 1;
    
        segTree = vector<int>(segTreeLen,0);
        segTreeUtil(arr, 0, arraySize-1, 0);
    }
    int segTreeUtil(vector<int>& arr, int ss, int se, int si) {
        
        if (ss == se) {
            segTree[si] = arr[ss];
            return segTree[si];
        }

        int mid = ss + (se-ss)/2;
        segTree[si] = segTreeUtil(arr, ss, mid, 2*si+1) +
                            segTreeUtil(arr, mid+1, se, 2*si+2);

        return segTree[si];
    }

    int getSumUtil(int qs, int qe, int ss, int se, int si) {
        // st lies in qrange
        // st is completely outside qrange
        // st is partially inside qrange

        if (se < qs || ss > qe) return 0;
        
        if (ss >= qs && se <= qe) return segTree[si];

        int mid = ss + (se-ss)/2;
        return getSumUtil(qs, qe, ss, mid, 2*si +1) + 
                getSumUtil(qs, qe, mid+1, se, 2*si+2);
    }

    void updateUtil(int ss, int se, int currIndex, int qi, int diff) {
        // qi lies inside ss, se
        // qi lies outside ss, se

        if (qi < ss || qi > se) return;

        segTree[currIndex] += diff;
        
        if (ss != se) {
            int mid = ss + (se-ss)/2;
            updateUtil(ss, mid, 2*currIndex+1, qi, diff);
            updateUtil(mid+1, se, 2*currIndex+2, qi, diff);
        }
    }

    int getSum(int qs, int qe) {
        
        if (qs<0 || qe>= arraySize || qe < qs) return INT_MIN;

        return getSumUtil(qs, qe, 0, arraySize-1, 0);
    } 
    bool update(int index, int diff) {
        if (index < 0 || index >= arraySize) return false;
        updateUtil(0, arraySize -1, 0, index, diff);
        return true;
    }

    void print() {
        for (auto &ele: segTree) {
            cout << ele << ", ";
        }
        cout << endl;
    }
};


int main() {
    vector<int> arr = {0,1,2,3,4,5,6};
    SegmentTree segTree = SegmentTree(arr);
    segTree.print();
    cout << "[2,5]: " << segTree.getSum(2,5) << endl;
    segTree.update(2,3);
    cout << "[2,5]: " << segTree.getSum(2,5) << endl;
}