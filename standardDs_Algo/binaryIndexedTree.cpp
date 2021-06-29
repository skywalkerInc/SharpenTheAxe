#include <bits/stdc++.h>
using namespace std;

class BIT {
public:
    vector<int> biTree;
    BIT(vector<int>& arr): biTree{vector<int>(arr.size() +1, 0)} {
        for (int i=0;i<arr.size(); i++) {
            update(i, arr[i]);
        }
    }

    int getSum(int qi) {
        qi += 1;
        int sum = 0;
        while (qi > 0) {
            sum += biTree[qi];
            qi -= qi & (-qi);
        }
        return sum;
    }
    bool update(int qi, int diff) {
        qi += 1;
        while (qi < biTree.size()) {
            biTree[qi] += diff;
            qi += qi & (-qi);
        }
        return true;
    }
    
    void print() {
        for (auto &ele: biTree) {
            cout << ele << ", ";
        }
        cout << endl;
    }

};


void testBIT() {
    vector<int> arr = {0,1,2,3,4,5,6};
    BIT biTree = BIT(arr);
    biTree.print();
    cout << "[0,4]: " << biTree.getSum(4) << endl;
    biTree.update(2, 3);
    cout << "[0,4]: " << biTree.getSum(4) << endl;
}

int main() {
    testBIT();
}
