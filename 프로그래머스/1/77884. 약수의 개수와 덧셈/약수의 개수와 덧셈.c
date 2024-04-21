#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int solution(int left, int right) {
    int answer = 0;
    int num = 0;
    
    for(int k=left; k<=right; k++) {
        num = 0;
        
        for(int i=1; i<=sqrt(k); i++) {
            if(k % i == 0) {
                num++;
                if (i != k / i) {
                    num++;
                }
            }
        }
        
        // 약수 짝수 더하기 & 홀수 빼기
        if(num % 2 == 0) {
            answer += k;
        } else {
            answer -= k;
        }
    }
    return answer;
}