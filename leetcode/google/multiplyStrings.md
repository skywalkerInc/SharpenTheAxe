```c++
class Solution {
public:
    //  456 * 123 =  //mul=8, mulVal=8 resNum=1 mc:0 sc:1, rs:0
    // 884010
    string multiply(string num1, string num2) { 
        if (num1 == "0" || num2 == "0") return "0";
        
        int n=num1.size(), m=num2.size(); 
        string res(n+m, '0');
        // cout <<res <<endl;
        
        int offset = 0;
        int mulCarry = 0;
        int sumCarry = 0;
        for(int i=n-1;i>=0;i--) {
            for (int j=m-1; j>=0;j--) {
                // num2 * num1 
                int a = num1[i] - '0';
                int b = num2[j] - '0';
                int mul = a*b;
                int resNum = (int)(res[offset+ m-1-j] - '0');
                // cout << res << ": " << offset+ m-1-j << ", " << res[offset+ m-1-j] <<endl;
                
                int mulVal = mul%10;
                
                int resSum = resNum + mulVal + mulCarry + sumCarry;
                
                if (resSum >= 10) sumCarry = resSum/10;
                else sumCarry = 0;
                
                if (mul >= 10) mulCarry = mul/10;
                else mulCarry = 0;
                
                // printf("mul: %d, rn: %d, rs: %d, mc: %d, sc: %d\n", mul, resNum, resSum, mulCarry, sumCarry);
                
                resSum = resSum%10;

                
                res[offset+m-1-j] = (char)(resSum + '0');
                
            }
            
            if (mulCarry > 0 || sumCarry > 0) {
                int carry = mulCarry + sumCarry;
                // cout << "carry: " <<carry <<endl;
                res[offset+m] = (char)(carry + '0');
                mulCarry = 0;
                sumCarry = 0;
            }
            offset += 1;
            // cout << res << endl;
        }
        
        while (res.back() == '0') {
            res.pop_back();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

/*
  num2: 333 (m)
  num1: 444 (n)

carry=1
2  331
   2331
   
2  5
*/
``