``` c++
#include <cstdlib>
class Solution {
public:
    double getSlope(vector<int>& p1, vector<int>& p2) {
        if (p1[0] - p2[0] == 0) //infinity
        {
            return INT_MAX;
        }
        else if (p1[1] - p2[1] == 0) {
            return 0;
        }
        
        return (double)((double)(p1[1] - p2[1]) / (double)(p1[0] - p2[0]));
        
    }
    
    bool isParallel(double s1, double s2) {
        if (s1 == s2) return true;
        
        return false;
    }
    
    bool isPerpendicular(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        double s1 = getSlope(p1, p2);
        double s2 = getSlope(p3, p4);
        
        if (s1 == INT_MAX && s2 == 0) return true;
        if (s1 == 0 && s2 == INT_MAX) return true;
        if (s1 != INT_MAX && s2 != INT_MAX) {
            if (s1 == 0 || s2 == 0) return false;
            
            if ((s1 > 0 && s2 >0) || (s1<0 && s2<0)) return false;
            
            if (abs(p1[0] - p2[0]) == abs(p3[1] - p4[1]) && (abs(p1[1] - p2[1]) == abs(p3[0] - p4[0])))
            {
                return true;
            }
        }
        return false;
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        //configure1: p1 & p2 | p3, p4
        double c1s1 = getSlope(p1, p2);
        double c1s2 = getSlope(p3, p4);
        bool c1perp = isPerpendicular(p1, p2, p3, p4);
        bool c1par = isParallel(c1s1, c1s2);
        
        //configure2: p1 & p3 | p2, p4
        double c2s1 = getSlope(p1, p3);
        double c2s2 = getSlope(p2, p4);
        bool c2perp = isPerpendicular(p1,p3, p2,p4);
        bool c2par = isParallel(c2s1, c2s2);
        
        //configure3: p1 & p4 | p2, p3
        double c3s1 = getSlope(p1, p4);
        double c3s2 = getSlope(p2, p3);
        bool c3perp = isPerpendicular(p1, p4, p2, p3);
        bool c3par = isParallel(c3s1, c3s2);
        
        // printf("%lf, %lf | %d, %d\n", c1s1, c1s2, c1perp, c1par);
        // printf("%lf, %lf | %d, %d\n", c2s1, c2s2, c2perp, c2par);
        // printf("%lf, %lf | %d, %d\n", c3s1, c3s2, c3perp, c3par);
            
        if (c1perp) {
            if (c2par && c3par) {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if(c2perp) {
            if (c1par && c3par) {
                return true;   
            }
            else
            {
                return false;
            }
        }
        else if(c3perp) {
            if (c2par && c1par) {
                return true;   
            }
            else
            {
                return false;
            }
        }
        else {
            return false;
        }
    }
};



```