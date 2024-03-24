#include <stdio.h>

int N;
int max = -1000000001;
int min = 1000000001;
int num[12]; // 2<= N <= 11 이니까
int sum = 0;

void calculate (int plus, int minus, int multiply, int divide, int sum, int x) {
    
    if(x == N-1) {
        if(sum > max) {
            max = sum;
        }
        if (sum < min) {
            min = sum;
        }
    }

    if(plus>0) {
        calculate(plus-1, minus, multiply, divide, sum+num[x+1], x+1);
    }
    if(minus>0) {
        calculate(plus, minus-1, multiply, divide, sum-num[x+1], x+1);
    }
    if(multiply>0) {
        calculate(plus, minus, multiply-1, divide, sum*num[x+1], x+1);
    }
    if(divide>0) {
        calculate(plus, minus, multiply, divide-1, sum/num[x+1], x+1);
    }
}

int main() {
    scanf("%d", &N);
    
    for(int i=0; i<N; i++) {
        int temp;
        scanf("%d", &temp);
        num[i] = temp;
    }
    
    int plus, minus, multiply, divide;
    scanf("%d %d %d %d", &plus, &minus, &multiply, &divide);

    calculate(plus, minus, multiply, divide, num[0], 0);
    printf("%d\n%d", max, min);
}