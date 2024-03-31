#include <stdio.h>

void cal(int a, int b, int c){
    int result = 0;
    if(a==b && b==c) {
        result = 10000 + a*1000;
        printf("%d", result);
    } else if(a==b) {
        result = 1000 + a*100;
        printf("%d", result);
    } else if(b==c) {
        result = 1000 + b*100;
        printf("%d", result);
    } else if(c==a) {
        result = 1000 + c*100;
        printf("%d", result);
    } else {
        if(a>b) {
            if(a>c) {
                result = a*100;
                printf("%d", result);
            } else{
                result = c*100;
                printf("%d", result);
            }
        } else if(b>c) {
            if(b>a) {
                result = b*100;
                printf("%d", result);
            }
        } else if(c>a) {
            if(c>b) {
                result = c*100;
                printf("%d", result);
            }
        }
    }
}

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    cal(a,b,c);
}