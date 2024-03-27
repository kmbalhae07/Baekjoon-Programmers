#include <stdio.h>

long long arr[106];

long long tri(int n) {
    if(n<=3) {
        return 1;
    } else if(n==4 || n==5) {
        return 2;
    } else if(arr[n] == 0) {
        arr[n] = tri(n-5) + tri(n-1);
    }
    return arr[n];
}
 
int main() {
    int T;
    scanf("%d", &T);

    for(int i=0; i<T; i++) {
        int n;
        scanf("%d", &n);
        long long result = tri(n);
        printf("%lld\n", result);
    }
}