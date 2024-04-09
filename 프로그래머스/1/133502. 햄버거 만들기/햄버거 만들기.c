#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// ingredient_len은 배열 ingredient의 길이입니다.
int solution(int ingredient[], size_t ingredient_len) {
    int* stack = (int*)malloc(ingredient_len * sizeof(int));
    int answer = 0;
    int top = -1;
    
    for(int i = 0; i < ingredient_len; i++) {
        stack[++top] = ingredient[i];
        if (stack[top] == 1 && top >= 3) {
            if(stack[top-1] == 3 && stack[top-2] == 2 && stack[top-3] == 1) {
                answer++;
                top-=4;
            }
        }
    }
    
    free(stack); 
    return answer;
}
