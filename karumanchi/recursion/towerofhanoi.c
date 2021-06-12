void TowerOfHanoi(int n, char S, char A, char T) {

if (n==1) {
printf(“move 1 from %c to %c”, S, T);
}

//move n-1 disk to auxiliary rod
TowerOfHanoi(n-1, S,T ,A);

printf(“move %d from %c to %c”, n, S, T);

//move the n-1 which were moved in auxiliary to target
TowerOfHanoi(n-1, A, T, S);

}
