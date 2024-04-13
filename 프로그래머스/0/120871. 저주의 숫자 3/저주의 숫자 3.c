#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 1;
    
    for(int i=1; i<n; i++) {
        if((answer+1)/10 == 3) {
            answer = 40;
        } else if((answer+1)/10==13 || (answer+2)/10==13) {
            answer = 140;
        } else if((answer+1)%10==3) {
            if((answer+2)%3==0) {
                answer+=3;
            } else {
                answer+=2;
            }
        } else if((answer+1)%3==0) {
            if(((answer+2)%10)==3) {
                answer+=3;
            } else {
                answer+=2;
            }
        } else {
            answer++;
        }
    }
    
    return answer;
}