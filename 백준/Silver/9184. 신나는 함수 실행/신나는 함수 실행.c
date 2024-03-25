#include <stdio.h>
#define MAX 21
int dp[MAX][MAX][MAX];

int w(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) return 1;
    if (a > 20 || b > 20 || c > 20) return w(20, 20, 20);

    if (dp[a][b][c] != 0) return dp[a][b][c];

    if (a < b && b < c) {
        dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
        return dp[a][b][c];
    } else {
        dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
        return dp[a][b][c];
    }
}

int main() {
    int a, b, c;
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            for (int k = 0; k < MAX; ++k) {
                dp[i][j][k] = 0;
            }
        }
    }

    while (1) {
        scanf("%d %d %d", &a, &b, &c);
        if (a == -1 && b == -1 && c == -1) 
            break;
        int result = w(a, b, c);
        printf("w(%d, %d, %d) = %d\n", a, b, c, result);
    }
    return 0;
}