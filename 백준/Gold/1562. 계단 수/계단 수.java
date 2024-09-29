import java.util.Scanner;

public class Main {
    static final int MOD = 1000000000; // 결과를 출력할 때 사용할 모듈로
    static final int MAX_LENGTH = 100; // 최대 길이
    static final int DIGITS = 10; // 사용할 수 있는 숫자 (0~9)
    static long[][][] dp; // dp[length][lastDigit][mask]

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt(); // 수의 길이
        dp = new long[N + 1][DIGITS][1 << DIGITS]; // DP 배열 초기화

        // 첫 번째 자리에는 1~9의 숫자만 올 수 있으므로 초기화 (0은 못함)
        for (int i = 1; i < DIGITS; i++) {
            dp[1][i][1 << i] = 1; 
        }

        // DP 수행
        fillDP(N);

        // 답 계산
        long answer = calculateAnswer(N);
        System.out.println(answer);
    }

    private static void fillDP(int N) {
        // 각 길이에 대해 가능한 경우를 계산
        for (int length = 1; length < N; length++) {
            for (int lastDigit = 0; lastDigit < DIGITS; lastDigit++) {
                for (int mask = 0; mask < (1 << DIGITS); mask++) {
                    if (dp[length][lastDigit][mask] == 0) continue; // 유효하지 않은 경우

                    // 다음 자릿수를 결정
                    for (int nextDigit : new int[]{lastDigit - 1, lastDigit + 1}) {
                        if (nextDigit >= 0 && nextDigit < DIGITS) {
                            // 새로운 마스크 계산
                            int newMask = mask | (1 << nextDigit);
                            dp[length + 1][nextDigit][newMask] = (dp[length + 1][nextDigit][newMask] + dp[length][lastDigit][mask]) % MOD;
                        }
                    }
                }
            }
        }
    }

    private static long calculateAnswer(int N) {
        long totalCount = 0;

        // 모든 숫자가 사용된 경우의 수를 합산
        for (int lastDigit = 0; lastDigit < DIGITS; lastDigit++) {
            totalCount = (totalCount + dp[N][lastDigit][(1 << DIGITS) - 1]) % MOD;
        }

        return totalCount;
    }
}
