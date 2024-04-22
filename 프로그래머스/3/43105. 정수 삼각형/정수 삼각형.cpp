#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<vector<int>> dp(triangle); 

    for (int i = 1; i < triangle.size(); ++i) {
        for (int j = 0; j < triangle[i].size(); ++j) {
            if (j == 0) {
                dp[i][j] += dp[i - 1][j];
            }
            else if (j == triangle[i].size() - 1) {
                dp[i][j] += dp[i - 1][j - 1];
            }
            else {
                dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);
            }
        }
    }

    // 삼각형의 마지막 층에서 최대값
    for (int i = 0; i < dp.back().size(); ++i) {
        answer = max(answer, dp.back()[i]);
    }

    return answer;
}
