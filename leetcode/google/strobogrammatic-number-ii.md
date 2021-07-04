```c++
class Solution {
    map<int, int> numMap;
public:
    
    void util(vector<string>& res, int n, int i, string stNum) {
        
        // cout << stNum << endl;
        if (i == (n+1)/2) {
            int j = n/2-1;
            // printf("n: %d, i: %d, j=%d ", n, i, j);
            // cout << stNum << endl;
            for (; j>=0; j--) {
                char ch = char(numMap[stNum[j] - '0'] + '0');
                // printf("j: %d, stNum[j]: %c, numMap: %d ", j, stNum[j], numMap[stNum[j] - '0']);
                stNum.push_back(ch);
            }
            
            res.push_back(stNum);
            return;
        }
        
        for (auto &ele: numMap) {
            if (n%2==1 && i==n/2 && numMap[ele.first] != ele.first) continue;
            
            stNum.push_back(char(ele.first + '0'));
            util(res, n, i+1, stNum);
            stNum.pop_back();
        }
    }
    
    vector<string> findStrobogrammatic(int n) {
        numMap[0] = 0;
        numMap[1] = 1;
        numMap[6] = 9;
        numMap[8] = 8;
        numMap[9] = 6;
        
        if (n == 0) return vector<string>{};
        if (n==1) return vector<string>{"0","1","8"};
        
        vector<string> res;
        for (auto &ele: numMap) {
            if (ele.first != 0) {
                string stNum;
                stNum.push_back(char(ele.first + '0'));
                // cout << "stNum: " << stNum << endl;
                util(res, n, 1, stNum);    
            }
        }
        
        return res;
    }
};

/*
[0-9][0-9]...

0 1 2 3

first num: can't be 0
n/2 combination


0: 0
1: 1
6: 9
8: 8
9: 6

n=0 : 0
n=1: fixed list
n=2:
1
6
8
9


*/
```