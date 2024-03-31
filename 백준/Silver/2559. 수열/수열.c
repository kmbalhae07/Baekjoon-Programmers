#include <stdio.h>

int arr[100001];
int max = -10000001;

int cal(int N, int k) {
    int first = 0;
    
    for(int i=0; i<k; i++) {
        first+=arr[i];
    }

    if(first > max) {
        max = first;
    }
    
    int next = first;
    
    for(int p=0; p<N-k; p++) {
        next = next + arr[k+p] - arr[p];

        
        if(next > max) {
            max = next;
        }
    }

    return max;
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    for(int i=0; i<N; i++) {
        int num;
        scanf("%d", &num);
        arr[i] = num;
    }

    cal(N,K);
    printf("%d", max);
}