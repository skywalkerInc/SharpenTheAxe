#include <bits/stdc++.h>
#include "rough.cpp"
using namespace std;

class Compare {
    vector<int> param;
public:
    Compare(vector<int> p): param(p) {}

    bool operator() (int a, int b) {
        return param[a] < param[b];
    }
};
class CppCommonSyntex {
public:
    CppCommonSyntex() {}

    void sortingTest() {
        cout << "doing sorting test" << endl;
        vector<int> toSort = {6,9, 3, 4, 1};
        vector<int> indices = {0, 1, 2, 3, 4};
        sort(indices.begin(), indices.end(), Compare(toSort));
        for (auto &i: indices) {
            cout << i << " : " << toSort[i] << endl;
        }
    }
};



int main() {
    // CppCommonSyntex cpp = CppCommonSyntex();
    // cpp.sortingTest();

    Rough rough;
    rough.Solution();
}

