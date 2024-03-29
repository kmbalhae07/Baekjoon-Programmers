#include <stdio.h>

int arr[100001];
int res_max;
int cur_max;

int cal(int n) {
    res_max = arr[0];
    cur_max = arr[0];
    
    for(int i = 1; i < n; i++) {
        if(arr[i] > cur_max + arr[i]) {
            cur_max = arr[i];
        } else {
            cur_max += arr[i];
        }
        
        if(cur_max > res_max) {
            res_max = cur_max;
        }
    }
    return res_max;
}

int main() {
    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        int temp;
        scanf("%d", &temp);
        arr[i] = temp;
    }
    
    int result = cal(n);
    printf("%d", result);
    
    return 0;
}