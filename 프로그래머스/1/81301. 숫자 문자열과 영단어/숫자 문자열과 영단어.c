#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int solution(const char* s) {
    int answer = 0;
    int size = strlen(s);

    char* numbers[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int values[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int start = 0;
    for(int i = 0; i < size; ) { //i++ 쓰면 안됨
        // 현재 문자가 숫자인 경우
        if(s[i] >= '0' && s[i] <= '9') {
            answer = answer * 10 + (s[i] - '0');
            i++;
        } else { // 현재 문자가 숫자가 아닌 경우
            for(int j = 0; j < 10; j++) {
                int num_length = strlen(numbers[j]);
                
                // 현재 문자열과 숫자 문자열을 비교하여 일치하는지 확인
                if(strncmp(s + i, numbers[j], num_length) == 0) {
                    answer = answer * 10 + values[j];
                    i += num_length;
                    break;
                }
            }
        }
    }

    return answer;
}
