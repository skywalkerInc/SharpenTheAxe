## 30mins
```
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
class Solution {
public:
    string decodeString(string s) {
        string res;
        stack <char> st;
        
        //3[a2[c]]
        //st: 3 [ a c c
        //repStr = c
        int curr = 0;
        while (curr < s.length()) {
            
            if (s[curr] == ']')
            {
                string repStr = "";
                int k = 0;
                while (!st.empty() && st.top() != '[') 
                {
                    repStr.push_back(st.top()); st.pop();
                }
                
                st.pop(); //remove '['
                
                while(!st.empty() && isdigit(st.top())) {
                    k = atoi((const char *)&st.top()); 
                    st.pop();
                }
                
                
                for (int i=0; i<k; i++) {
                    for(int i=repStr.size()-1; i>=0; i--) {
                        st.push(repStr[i]);
                    }    
                }
                
            }
            
            if (s[curr] != ']')
                st.push(s[curr]);
                printf("st: %c\n", s[curr]);
            
            curr++;
            
        }
        
        while (!st.empty()) {
            res.push_back(st.top()); st.pop();
        }
        
        string ret = "";
        for (int i=res.size()-1; i>=0; i--) {
            ret.push_back(res[i]);
        }
        
        return ret;
    }
};



```