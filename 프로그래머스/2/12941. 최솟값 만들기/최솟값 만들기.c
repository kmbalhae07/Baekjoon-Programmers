#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void quickSort(int arr[], int L, int R) {
    int left = L, right = R;
    int pivot = arr[(L+R) / 2];

    int temp;
    
    do {
        while(arr[left] < pivot)
            left++;
        while(arr[right] > pivot)
            right--;
        
        if(left<=right) {
            temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            
            left++;
            right--;
        }
    } while(left<=right);
    
    if(L<right)
        quickSort(arr, L, right);
    if(left<R)
        quickSort(arr, left, R);
}

int solution(int A[], size_t A_len, int B[], size_t B_len) {
    int answer = 0;
    quickSort(A, 0, A_len-1);
    quickSort(B, 0, B_len-1);
    
    for(int i=0; i<A_len; i++) {
        answer+=A[i] * B[B_len-i-1];
    }
    
    return answer;
}