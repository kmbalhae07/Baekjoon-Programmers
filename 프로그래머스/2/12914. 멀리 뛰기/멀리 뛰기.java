class Solution {
    public int solution(int n) {
        final int MOD = 1234567;
        int[] dp = new int[n + 1];
        
        dp[1] = 1;
        if (n >= 2) {
            dp[2] = 2;
        }
        
        for (int i = 3; i <= n; i++) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
        }
        
        return dp[n];
    }
}
