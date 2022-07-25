```c++
class Solution {
public:
    int getInt(char ch) {
        return (char)(ch - '0');
    }
    char getChar(int val) {
        return (int)(val + '0');
    }
    int getNextMaxDigit(set<int>& digits, int digit) {
        int nextMax = -1;
        for (auto &val: digits) {
            if (val > digit) {
                return val;
            }
        }
        return nextMax;
    }
    
    bool isValid(string res) {
        if (getInt(res[0]) > 2 || getInt(res[3]) > 5) return false; // HH, MM
        if (getInt(res[1]) >3 && getInt(res[0]) == 2) return false; // HH
        return true;
    }
    
    void fillMin(string& res, int index, int minVal) {
        for(int i=index; i<res.size(); i++) {
            if(res[i] != ':') {
                res[i] = getChar(minVal);
            }
        }
    }
    
    string nextClosestTime(string time) {
        set<int> digits;
        string res = ""; res += time;
        for (auto &ch: time) {
            if (ch != ':') {
                digits.insert(getInt(ch));
            }
        }
        
        int index = time.size()-1;
        while (index>=0) {
            if(time[index--] == ':') continue;
            
            // current index: index+1
            int immediateMax = getNextMaxDigit(digits, getInt(time[index+1]));
            if (immediateMax == -1) continue;
            
            res[index+1] = getChar(immediateMax);
            printf("index: %d, immediateMax: %d, res: %s, time[index]: %c\n", index+1, immediateMax, res.c_str(), time[index+1]);
            if (isValid(res)) {
                fillMin(res, index+2, *(digits.begin()));
                return res;
            }
            cout << "not valid" << endl;
            res[index+1] = time[index+1];
        }
        
        cout << "covert all to min" << endl;
        fillMin(res, 0, *(digits.begin()));
        
        return res;
    }
};

/*
"19:34" | "19:39"
"23:59" | "22:22"

1. digits present
2. greater than current, circuler

19:34
HH:MM
0<=HH<24
0<=MM<60
[1,3,4,9]

23:59 : 22:22
[2,3,5,9]

15:49  | 15:51
[1,4,5,9]

go though from righ to left, if you find any replacement is possible then replace the later by minimum
*/
```