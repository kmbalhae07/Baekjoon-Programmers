#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
bool solution(const char* s) {
    int char_num = strlen(s);
    if(char_num % 2 == 1) {
        return false;
    }
    
    //문자열 처리 -> 스택 자료 구조
    //스택에서 효율성 때문에 동적으로 할당해보기
    
    int stack_size = char_num / 2;
    char* stack = (char*)malloc(stack_size * sizeof(char));
    bool answer = true;
    int top = -1;
    
    for(int i=0; s[i] != '\0'; i++) {
        if(s[0] == ')') {
            free(stack);
            return false;
        }
        
        if(s[i] == '(') {
            if(top+1 >= stack_size) {
                answer = false;
                break;
            }
            stack[++top] = '(';
        } else if(s[i] == ')') {
            if(top == -1 || stack[top] != '(') {
                answer = false;
                break;
            }
            top--;
        }
    }
    
    if(top != -1) {
        answer = false;
    }
    
    free(stack);
    return answer;
}