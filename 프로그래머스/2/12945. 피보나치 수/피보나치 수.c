#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int arr[100001];

int pivo(int n) {    
    if (arr[n] != -1)
        return arr[n];
    else
        return arr[n] = (pivo(n-1)%1234567) + (pivo(n-2)%1234567);
}

int solution(int n) {
    int answer = 0;
    for(int i=0; i<=n; i++) {
        arr[i] = -1;
    }
    
    arr[0] = 0;
    arr[1] = 1;
    
    answer = pivo(n)%1234567;
    return answer;
}