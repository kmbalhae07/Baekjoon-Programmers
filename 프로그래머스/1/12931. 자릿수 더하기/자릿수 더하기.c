#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int solution(int n) {
    int answer = 0;
    char s1[10];
    sprintf(s1, "%d", n);
    int size = strlen(s1);
    
    for(int i=0; i<size; i++) {
        answer += s1[i] - '0';
    }
    
    
    return answer;
}