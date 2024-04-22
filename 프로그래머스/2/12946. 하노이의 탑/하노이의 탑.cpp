#include <vector>

using namespace std;

void HanoiTower(vector<vector<int>>& answer, int n, int start, int dest, int temp) {
    if (n == 1) {
        answer.push_back({ start, dest });
        return;
    }
    
    HanoiTower(answer, n - 1, start, temp, dest);
    answer.push_back({ start, dest });
    HanoiTower(answer, n - 1, temp, dest, start);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    HanoiTower(answer, n, 1, 3, 2);
    return answer;
}
