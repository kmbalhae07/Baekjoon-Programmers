#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void quickSort(int arr[], int L, int R) {
    int left = L, right = R;
    int pivot = arr[(L+R) / 2];
    int temp;
    
    do {
        while(arr[left] < pivot) {
            left++;
        } while(arr[right] > pivot) {
            right--;
        } if(left <=right) {
            temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    } while(left <= right);
    
    if(L<right)
        quickSort(arr, L, right);
    if(left<R)
        quickSort(arr, left, R);
}

int* solution(int k, int score[], size_t score_len) {
    int* answer = (int*)malloc(sizeof(int) * (score_len + 1));
    int* arr = (int*)malloc(sizeof(int) * (k+1));
    
    for(int i=0; i<score_len; i++) {
        if(i<k) {
            arr[i] = score[i];
            quickSort(arr, 0, i);
            answer[i] = arr[0];
        } else {        // 명예의 전당 넘어가는 경우
            if(score[i] >= arr[0]) {
                arr[0] = score[i];
            }
            quickSort(arr, 0, k-1);
            answer[i] = arr[0];
        }
    }
    
    return answer;
}
