#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(int food[], size_t food_len) {
    int size = 0;
    for(int x=0; x<food_len; x++) {
        size+= food[x];
    }
    
    char* answer = (char*)malloc(sizeof(char) * (size+1));
    char* arr = (char*)malloc(sizeof(char) * (size+1));
    int num=0;
    
    //물 이전 배열
    for(int i=1; i<food_len; i++) {
        int temp = food[i]/2;
        for(int k=0; k<temp; k++) {
            answer[num] = i + '0';
            arr[num] = i + '0';
            num++;
        }
    }
    
    //물
    answer[num]='0';
    
    //물 이전 배열 반전
    int max = num-1;
    for(int p=0; p<num/2; p++) {
        int temp = arr[p];
        arr[p] = arr[max];
        arr[max] = temp;
        max--;
    }
    
    int plus=1;
    for(int y=0; y<num; y++) {
        answer[num+plus] = arr[y];
        plus++;
    }
    answer[num+plus] = '\0'; 
    
    return answer;
}