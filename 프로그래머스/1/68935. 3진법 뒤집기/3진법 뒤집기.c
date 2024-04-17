#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solution(int n) {
    int answer = 0;
    
    int arr[32];
    int i=0;
    int mok, nmg;

    //3진환
    while(n!=0) {
        arr[i] = n%3;
        n /= 3;
        i++;
    }
    
    //뒤집기
    int back = i;
    for(int k=0; k<=i; k++) {
        int temp = arr[k];
        arr[k] = arr[back];
        arr[back] = temp;
        back--;
    }
    
    //10진환
    int ba = 0;
    for(int p=i-1; p>=0; p--) {
        answer+= arr[p] * pow(3, ba);
        ba++;
    }
    
    return answer;
}