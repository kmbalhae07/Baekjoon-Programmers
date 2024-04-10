#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* s) {
    int size = strlen(s);
    int arr[123] = {0};
    char* answer = (char*)malloc(sizeof(char) * (size+1));
    strcpy(answer, s);
    
    for(int i=0; i<size; i++) {
        int temp = s[i];
        arr[temp]++;
    }
    
    
    int index = 0;
    for(int i = 122; i >= 97; i--) { 
        if(arr[i] != 0) {
            for(int j = 0; j < arr[i]; j++) {
                answer[index++] = i;
            }
        }
    }
    for(int i = 90; i >= 65; i--) { 
        if(arr[i] != 0) {
            for(int j = 0; j < arr[i]; j++) {
                answer[index++] = i;
            }
        }
    }
    
    answer[index] = '\0'; 
    return answer;
}