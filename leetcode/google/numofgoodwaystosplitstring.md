## 15min

``` c++

#include <strings.h>

int numSplits(char * s){
    
    int res = 0;
    
    int lSplit[26];
    int rSplit[26];
    for(int i = 0; i<26;i++) {
        lSplit[i] =0;
        rSplit[i] = 0;
    }
    
    int lDisCount = 0;
    int rDisCount = 0;
    
    int sSize = strlen(s);
    for(int i=0; i<sSize;i++) {
        int ch = (int)(s[i] - 'a');
        
        if (rSplit[ch] == 0) {
            rDisCount++;
        }
        
        rSplit[ch]++;
    }
    
    for(int i=0;i<sSize-1;i++) {
        int ch = (int)(s[i] - 'a');
        
        if(lSplit[ch] == 0) {
            lDisCount++;
        }
        lSplit[ch]++;
        
        rSplit[ch]--;
        if(rSplit[ch] == 0) {
            rDisCount--;
        }
        
        if(lDisCount == rDisCount) {
            res++;
        }
    }
    return res;
}

```