#include <stdio.h>
int arr[1000001]; //10000개 까지 있으니까

int fibona(int n) {
    if(n == 1) {
        return 1;
    } else if (n == 2) {
        return 2;
    } else if(arr[n] == 0) {
        arr[n] = (fibona(n-2) + fibona(n-1)) % 15746;
    }
    return arr[n];
}

int main() {
    int N;
    scanf("%d", &N);
    fibona(N);
    printf("%d", fibona(N));
}