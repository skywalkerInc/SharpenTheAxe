#include <stdio.h>


int checksort(int A[], int n) {
   
    if (n <= 2) {
        return 1;
    }

    int ret = ((A[n-1] >= A[n-2]) && (A[n-2] >= A[n-3])) || 
            ((A[n-1] <= A[n-2]) && (A[n-2] <= A[n-3]));
    
    if (ret) {
        return checksort(A, n-1);
    }

    return 0;

}

int main() {
    int arr[5] = {5,3,3,2,1};
    int ret = checksort(arr, 5);
    printf("%d\n", ret);
    return 0;
}