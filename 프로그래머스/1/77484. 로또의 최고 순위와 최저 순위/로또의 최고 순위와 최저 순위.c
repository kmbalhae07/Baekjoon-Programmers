#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int ranking(int num) {
    switch (num) {
        case 6: return 1;
        case 5: return 2;
        case 4: return 3;
        case 3: return 4;
        case 2: return 5;
        default: return 6;
    }
}

int* solution(int lottos[], size_t lottos_len, int win_nums[], size_t win_nums_len) {
    int* answer = (int*)malloc(sizeof(int) * 2);
    
    //정렬해두기
    qsort(lottos, lottos_len, sizeof(int), compare);
    qsort(win_nums, win_nums_len, sizeof(int), compare);

    //동일한 수 개수 구하기
    int num = 0;
    int zero_check = 0;
    for(int i=0; i<lottos_len; i++) {
        if(lottos[i] == 0) {
                zero_check++;
            }
        
        for(int k=0; k<win_nums_len; k++) {
            if(lottos[i] == win_nums[k] ) {
                num++;
            }
        }
    }
    
    //순위 구하기
    int low_rank = ranking(num);
    num += zero_check;
    int high_rank = ranking(num);
    
    answer[0] = high_rank;
    answer[1] = low_rank;
    return answer;
}