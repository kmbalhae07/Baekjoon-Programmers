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
    if(left<R)
        quickSort(arr,left,R);
}

int solution(int numbers[], size_t numbers_len) {
    quickSort(numbers, 0, numbers_len-1);
    
    int answer = numbers[numbers_len-1] * numbers[numbers_len-2];
    return answer;
}