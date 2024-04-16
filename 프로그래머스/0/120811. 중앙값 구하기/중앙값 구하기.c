#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void quickSort(int arr[], int L, int R){
    int pivot = arr[(L + R) / 2];
    int left = L, right = R;
    int temp;
    
    do {
       while(arr[left] < pivot) {
           left++;
       } while (arr[right] > pivot) {
           right--;
       } if(left<=right) {
           temp = arr[left];
           arr[left] = arr[right];
           arr[right] = temp;
           left++;
           right--;
       }
    } while(left<=right);
    
    if(L<right)
        quickSort(arr,L,right);
    if(left<R) // 수정
        quickSort(arr,left,R);
}

int solution(int array[], size_t array_len) {
    quickSort(array, 0, array_len-1);
    int answer = array[array_len/2 ];
    return answer;
}