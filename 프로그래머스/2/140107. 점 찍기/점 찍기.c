#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

long long solution(int k, int d) {
    long long answer = 0;
    int y, j;
    
    for(y=0; y<=d ; y+=k){
        answer += (int) (pow(pow(d,2)-pow(y,2), 0.5)/k) + 1;
    }

    return answer;
}