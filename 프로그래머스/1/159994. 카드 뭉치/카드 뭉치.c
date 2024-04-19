#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h> 

char* solution(const char* cards1[], size_t cards1_len, const char* cards2[], size_t cards2_len, const char* goal[], size_t goal_len) {
    size_t size = cards1_len + cards2_len;
    char* answer = (char*)malloc(sizeof(char) * (size + 1)); 

    strcpy(answer, "");

    size_t k1 = 0;
    size_t k2 = 0;
    for (size_t i = 0; i < goal_len; i++) {
        if (k1 < cards1_len && strcmp(cards1[k1], goal[i]) == 0 ) {
            k1++;
        } else if (k2 < cards2_len && strcmp(cards2[k2], goal[i]) == 0) { 
            k2++;
        } else {
            strcpy(answer, "No");
            break;
        }
    }

    if (strlen(answer) == 0) {
        strcpy(answer, "Yes");
    }
    
    return answer;
}
