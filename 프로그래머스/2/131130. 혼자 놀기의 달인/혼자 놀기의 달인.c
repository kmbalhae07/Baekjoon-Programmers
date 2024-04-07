#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// cards_len은 배열 cards의 길이입니다.
int solution(int cards[], size_t cards_len) {
    int answer = 0;
    bool visited[101] = {false};
    
    int max_num = 0;
    int second_max_num = 0;
     
    for (int i = 0; i < cards_len; i++) {
        int num = 0; 
        int current_box = i; 
        
        while (!visited[current_box]) {
            visited[current_box] = true; 
            num++; 
            current_box = cards[current_box] - 1; 
        }

        if (num > max_num) {
            second_max_num = max_num;
            max_num = num;
        } else if (num > second_max_num) {
            second_max_num = num;
        }
    }
    
    answer = max_num * second_max_num;
    return answer;
}