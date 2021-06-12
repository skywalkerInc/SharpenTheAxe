#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void GenerateStrings(char A[], int n) {
	if (n < 1) {
		printf("%s\n", A);
    } else {
        A[n-1] = '0';
        GenerateStrings(A, n-1);
        A[n-1] = '1';
        GenerateStrings(A, n-1);
    }
	
}

void GenerateStrings1(char A[], int n, int k) {

    if (n < 1) {
        printf("%s\n", A);
    }
    else {
        for (int i =0; i<k; i++) {
            A[n-1] = 'a' + i;
            GenerateStrings1(A, n-1, k)
        }
    }

}

int main() {
    char A[3];
    GenerateStrings(A, 3);
}