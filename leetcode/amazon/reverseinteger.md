```


int reverse(int x){
    // int sign = x >> 31;
    int rev = 0;
    
    while (x != 0) {
        int rem = x%10;
        x = x/10;
        //check difference between limit and rem
        
        if (rev > INT_MAX/10 || (rev==INT_MAX/10 && rem > 7 )) {
            return 0;
        }
        if (rev < INT_MIN/10 || (rev==INT_MIN/10 && rem < -8)) {
            return 0;
        }
        rev = rev * 10 + rem;
    }
    return rev;
}
```