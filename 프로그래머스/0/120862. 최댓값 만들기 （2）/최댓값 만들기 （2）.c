#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    int num1 = *(int *)a;    
    int num2 = *(int *)b;    

    if (num1 < num2)    
        return -1;     
    
    if (num1 > num2)    
        return 1;           
}

int solution(int numbers[], size_t numbers_len) {
    int answer = 0;
    int back_max = 0, front_max = 0;
    
    //음수는 음수끼리 양수는 양수끼리 곱해서 최댓값 구해보기
    qsort(numbers, numbers_len, sizeof(int), compare);
    
    back_max = numbers[0] * numbers[1];
    front_max = numbers[numbers_len-1] * numbers[numbers_len-2];
   
    if(back_max > front_max)
        answer = back_max;
    else
        answer = front_max;
        
    return answer;
}