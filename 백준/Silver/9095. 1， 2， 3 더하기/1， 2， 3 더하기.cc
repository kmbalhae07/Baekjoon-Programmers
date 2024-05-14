#include <stdio.h>

int arr[13];

int way(int num) {
    if(num==1) {
        arr[1] = 1;
    } else if(num==2) {
        arr[2] = 2;
    } else if(num==3) {
        arr[3] = 4;
    } else {
        arr[num] = way(num-1) + way(num-2) + way(num-3);
    }

    return arr[num];
}

int main() {
    int T;
    scanf("%d", &T);

    for(int i=0; i<T; i++) {
        int num;
        scanf("%d", &num);
        way(num);
        printf("%d\n", arr[num]);
    }
}