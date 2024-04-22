#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void quard(int** arr, size_t start_row, size_t start_col, size_t arr_rows, size_t arr_cols, int* answer) {
    if (arr_rows == 1 && arr_cols == 1) {
        answer[arr[start_row][start_col]]++;
        return;
    }

    int zero = 0, one = 0;
    for (int i = start_row; i < start_row + arr_rows; i++) {
        for (int j = start_col; j < start_col + arr_cols; j++) {
            if (arr[i][j] == 0)
                zero++;
            else
                one++;
        }
    }

    //같으면 answer 증가, 같지 않으면 재귀함수로 다시 반복하기
    if (zero == arr_rows * arr_cols) {
        answer[0]++;
        return;
    } else if (one == arr_rows * arr_cols) {
        answer[1]++;
        return;
    } else {
        size_t half_rows = arr_rows / 2;
        size_t half_cols = arr_cols / 2;

        //왼쪽 상단, 오른쪽 상단, 왼쪽 하단, 오른쪽 하단
        quard(arr, start_row, start_col, half_rows, half_cols, answer);
        quard(arr, start_row, start_col + half_cols, half_rows, half_cols, answer);
        quard(arr, start_row + half_rows, start_col, half_rows, half_cols, answer); 
        quard(arr, start_row + half_rows, start_col + half_cols, half_rows, half_cols, answer); 
    }
}

int* solution(int** arr, size_t arr_rows, size_t arr_cols) {
    int* answer = (int*)malloc(sizeof(int) * 2);
    answer[0] = 0, answer[1] = 0;
    quard(arr, 0, 0, arr_rows, arr_cols, answer);
    return answer;
}
