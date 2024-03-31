#include <stdio.h>

int main() {

    int arr[101];
    int N, M;
    scanf("%d %d", &N, &M);

    for(int p=1; p<=N; p++){
        arr[p] = p;
    }

    for(int o=0; o<M; o++) {
        int i, j;
        scanf("%d %d", &i, &j);

        for(int x = i; i<=j; i++) {
            int temp;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j--;
        }
    }

    for(int p=1; p<=N; p++){
        printf("%d ", arr[p]);
    }
}