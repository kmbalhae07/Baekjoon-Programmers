#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 정수를 문자열로 변환하는 함수
char* intToString(int num) {
    //1000 이하 원소
    char* str = (char*)malloc(5 * sizeof(char)); 
    sprintf(str, "%d", num); 
    return str;
}

int compare(const void *a, const void *b) {
    char str1[20], str2[20];
    sprintf(str1, "%s%s", *(char**)b, *(char**)a); 
    sprintf(str2, "%s%s", *(char**)a, *(char**)b);
    return strcmp(str1, str2);
}

char* solution(int numbers[], int numbersSize) {
    char** strNumbers = (char**)malloc(numbersSize * sizeof(char*));
    
     int allZero = 1;
    for (int i = 0; i < numbersSize; i++) {
        if (numbers[i] != 0) {
            allZero = 0;
            break;
        }
    }

    if (allZero) {
        char* result = (char*)malloc(2 * sizeof(char));
        strcpy(result, "0");
        return result;
    }
    
    //문자열로 만들어서 비교하기
    for (int i = 0; i < numbersSize; i++) {
        strNumbers[i] = intToString(numbers[i]);
    }

    qsort(strNumbers, numbersSize, sizeof(char*), compare);

    char* answer = (char*)malloc(100 * numbersSize * sizeof(char)); 
    strcpy(answer, "");
    for (int i = 0; i < numbersSize; i++) {
        strcat(answer, strNumbers[i]);
    }

    return answer;
}