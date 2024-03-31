#include <stdio.h>

int main() {

    int arr[31];
    for(int p=1; p<=30; p++){
        arr[p] = 0;
    }
    
    for(int i=1; i<=28; i++) {
        int n;
        scanf("%d", &n);
        arr[n] = n;
    }

    for(int p=1; p<=30; p++){
        if(arr[p] == 0) {
            printf("%d\n", p);
        }
    }
}