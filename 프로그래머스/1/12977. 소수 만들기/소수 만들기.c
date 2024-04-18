#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool isPrime(int num) {
    if (num <= 1) return false; 
    
    for (int i = 2; i < num; i++) {
        if (num % i == 0) 
            return false; 
    }
    return true;
}

int solution(int nums[], size_t nums_len) {
    int answer = 0;
    
    for(int i=0; i<nums_len; i++) {
        for (int k=i+1; k<nums_len; k++) {
            for(int j=k+1; j<nums_len; j++) {
                int sum = nums[i] + nums[j] + nums[k];
                if (isPrime(sum)) 
                    ++answer;
            }
        }
    }
    
    return answer;
}