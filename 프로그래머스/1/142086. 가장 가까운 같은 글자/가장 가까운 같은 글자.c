#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int* solution(const char* s) {
    int size = strlen(s);
    int* answer = (int*)malloc(sizeof(int) * size+1);
    int num[26] = {0};  //아스키코드 알파벳 범위
    
    //처음 나온 숫자는 무조건 -1이니까.
    answer[0] = -1;
    int standard = s[0]-'a';
    bool check = true;
    
    for(int i=1; i<size; i++) {
        if(s[i]-'a' == standard && check){
            answer[i] = i;
            num[s[i] -'a'] = i; 
            check = false;
        } else if(num[s[i] - 'a'] == 0){
            num[s[i] -'a'] = i; 
            answer[i] = -1;
        } else {
            int temp = i - num[s[i]-'a'];
            answer[i] = temp;
            num[s[i] -'a'] = i;
        }
    }
    
    return answer;
}