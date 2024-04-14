#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char str[180000];

int* solution(const char* s) {
    int* answer = (int*)malloc(sizeof(int) * 2);
    answer[0] = 0;
    answer[1] = 0;
    
    strcpy(str, s);
    int num, leng = strlen(str);
    while(1){
        answer[0]++;
        num = 0;
        for(int i=0; i<leng; i++) {
            if(str[i] == '0') 
                answer[1]++;
            else 
                num++;
        }
        //s가 1일경우 종료
        if(num==1)
            break;
        
        //2진수 변환
        leng = 0;
        while(num!=0) {
            str[leng++] = num%2 + '0';
            num = num/2;
        }
    }
    
    return answer;
}
