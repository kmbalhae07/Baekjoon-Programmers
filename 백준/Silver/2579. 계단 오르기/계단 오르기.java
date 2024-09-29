import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int stairCnt = sc.nextInt();
        int[] stair = new int[stairCnt + 1];
        int[] dp = new int[stairCnt + 1];
        
        for (int i = 1; i <= stairCnt; i++) {
            stair[i] = sc.nextInt();
        }

        if (stairCnt == 1) {
            System.out.println(stair[1]);
            return;
        }

        dp[1] = stair[1];  
        dp[2] = stair[1] + stair[2];  

        for (int i = 3; i <= stairCnt; i++) {
            dp[i] = Math.max(dp[i - 2] + stair[i], dp[i - 3] + stair[i - 1] + stair[i]);
        }

        System.out.println(dp[stairCnt]);
    }
}