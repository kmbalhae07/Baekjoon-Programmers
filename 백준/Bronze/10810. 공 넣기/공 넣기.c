#include <stdio.h>

int main() {
    int N, M;
    int arr[100];
    scanf("%d %d", &N, &M);

    for(int z=0; z<N; z++) {
        arr[z] = 0;
    }

    for(int p=0; p<M; p++) {
        int i,j,k;
        scanf("%d %d %d", &i, &j, &k);

        for(int q=i-1; q<j; q++) {
            arr[q] = k;
        }
    }

    for(int q=0; q<N; q++){
        printf("%d ", arr[q]);
    }
}