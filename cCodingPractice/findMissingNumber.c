#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

unsigned int findMissingNum(unsigned int N, unsigned int *arr)
{
    //printf("%d\n", N);
    uint8_t boolArr[N+1];
    
//     for(unsigned int n=0; n < N; n++)
//     {
//         printf("%d", arr[n]);
//     }
// 	printf("\n");
    
    //initialize boolArr with 0's
    for(unsigned int n = 0; n < N+1; n++)
    {
        boolArr[n] = 0;
    }
    
    //updating boolArr with all number
    for(unsigned int n = 0; n < N; n++)
    {
        boolArr[arr[n]-1] = 1;
        //printf("%d", arr[n]);
    }
    //printf("\n");
    
    
    //finding the 0
    for(unsigned int n = 0; n < N + 1; n++)
    {
        if(boolArr[n] == 0)
        {
            return n+1;
        }
    }
    
    return 0;
    
}

unsigned int findMissingNumSum(unsigned int N, unsigned int *arr)
{
    //take the sum of 1 to N
    //subtract all number in array from it, then the number missing is the remaining total.
    unsigned int sum = 0;
    int n = N + 1;
    sum = (n * (n + 1)) / 2;
    for(int i = 0; i < N; i ++)
    {
        sum = sum - arr[i];
    }
    
    return sum;
}

unsigned int findMissingNumXor(unsigned int N, unsigned int *arr)
{
    if(N==0)
    {
        return 0;
    }
    
    unsigned int xorN = 1;
    unsigned int xorArr = arr[0];
    
    for(unsigned int n=2; n<=N+1; n++)
    {
        xorN = xorN ^ n;
    }
    
    for(unsigned int i=1; i < N; i++)
    {
        xorArr = xorArr ^ arr[i];
    }
    
    return (xorArr ^ xorN);
}

int main() {
	//code
	
	//take input
	unsigned int testCaseNum = 0;
	unsigned int N = 0;
	unsigned int *arr;
	
	scanf("%d", &testCaseNum);
	//printf("%d\n", testCaseNum);
	
	for(int tn = 0; tn < testCaseNum; tn++)
	{
	    scanf("%d", &N);
	    //printf("%d\n", N);
	    
	    arr = (unsigned int *)malloc((N-1) * sizeof(unsigned int));
	    
	    for(unsigned int n=0; n < N-1; n++)
	    {
	        scanf("%d", &arr[n]);
	        //printf("%d", arr[n]);
	    }
	    //printf("\n");
	    
	    unsigned int output=0;
	    
	    //output = findMissingNum(N-1, arr);
	    //output = findMissingNumSum(N-1, arr);
	    output = findMissingNumXor(N-1, arr);
	    printf("%d\n", output);
	   
	    free(arr);
	    
	}
	
	return 0;
}
