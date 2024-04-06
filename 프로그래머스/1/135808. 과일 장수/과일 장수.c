#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// score_len은 배열 score의 길이입니다.
int solution(int k, int m, int score[], int score_len) {
    int answer = 0;
    int arr[10] = {0};
    
    for(int i=0; i<score_len; i++) {
        for(int z=1; z<=k; z++) {
            if(score[i] == z) {
                arr[z]++;
            }   
        }
    }
    
    int temp = 0;
    int a = m-temp;
    for(int p = k; p>=1; p--) {
        while(arr[p] >= a) {
            answer += p*m;
            arr[p] -= a;
            a = m;
        }
        if(arr[p] > 0) {
            a = a-arr[p];
        }
    }
    
    return answer;
}