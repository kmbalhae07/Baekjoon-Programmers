#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// dots_rows는 2차원 배열 dots의 행 길이, dots_cols는 2차원 배열 dots의 열 길이입니다.
int solution(int** dots, size_t dots_rows, size_t dots_cols) {
    int answer = 0;
    
    int x1 = dots[0][0], y1 = dots[0][1];
    int x2 = dots[1][0], y2 = dots[1][1];
    int x3 = dots[2][0], y3 = dots[2][1];
    int x4 = dots[3][0], y4 = dots[3][1];
    
    // 가로 길이와 세로 길이 계산 (절대값이니 abs)
    int width, height;
    if(x1 != x2)    width = abs(x2 - x1);
    else            width = abs(x3 - x1);
    
    if(y3 != y1)    height = abs(y3 - y1);
    else            height = abs(y2 - y1);
    
    answer = width * height;
    
    return answer;
}