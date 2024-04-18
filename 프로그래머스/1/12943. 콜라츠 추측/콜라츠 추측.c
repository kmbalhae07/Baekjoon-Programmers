#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void Collatz(long long num, int *answer) {
    if(num == 1) {
        *answer = 0;
        return;
    }
    
    if(*answer == 500) {
        *answer = -1;
        return;
    }
    
    if(num%2 == 0) {
        num /= 2;
        (*answer)++;
        if(num == 1)
            return;
        Collatz(num, answer);
    } else {
        num = 3*num + 1;
        (*answer)++;
        if(num == 1)
            return;
        Collatz(num, answer);
    }
}

int solution(long long num) {
    int answer = 0;
    Collatz(num, &answer);
    return answer;
}