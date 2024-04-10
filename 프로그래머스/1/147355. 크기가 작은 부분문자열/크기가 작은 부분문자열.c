#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int solution(const char* t, const char* p) {
    int answer = 0;
    int p_size = strlen(p); 
    int t_size = strlen(t); 
    
    for(int i = 0; i <= t_size - p_size; i++) { 
        if(strncmp(t + i, p, p_size) <= 0) { 
            answer++;
        } 
    }
    
    return answer;
}
