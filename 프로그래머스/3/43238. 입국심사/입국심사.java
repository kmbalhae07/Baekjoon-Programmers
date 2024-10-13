import java.util.*;
class Solution {
    public long solution(int n, int[] times) {
        long left = 1;
        long right =  1000000000000000000L;
        
        while (left < right) {
            long mid = (left + right) / 2;
            long temp = 0;
            for (int time : times) {
                temp += (mid / time);
            }
            
            if (temp < n) {
                left = mid+1;
            } else {
                right = mid;
            }
            
        }
        return left;
    }
}