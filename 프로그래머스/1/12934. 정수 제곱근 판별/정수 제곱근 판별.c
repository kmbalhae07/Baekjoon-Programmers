#include <math.h>

long long solution(long long n) {
    long long root = (long long)sqrtl(n); 
    if (root * root == n) { 
        return (root + 1) * (root + 1); 
    } else { 
        return -1; 
    }
}
