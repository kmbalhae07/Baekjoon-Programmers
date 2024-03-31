#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int arr[100];
    for(int k=1; k<=N; k++) {
        arr[k] = k;
    }
    
    for(int i=0; i<M; i++){
        int i, j;
        scanf("%d %d", &i, &j);

        int temp;
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    for(int k=1; k<=N; k++) {
        printf("%d ", arr[k]);
    }
}