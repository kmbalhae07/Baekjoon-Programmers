#include <vector>
#include <queue>
#include <utility> 

using namespace std;
const int INF = 987654321;

int BFS(vector<vector<int>> maps) {
    int n = maps.size();
    int m = maps[0].size();
    vector<vector<int>> dist(n, vector<int>(m, INF));
    queue<pair<int, int>> q;
    
    // 방향 상수 정의
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    
    q.push({0, 0});
    dist[0][0] = 1;
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        // 인접한 네 방향에 대해 탐색
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            // 범위를 벗어난 경우 & 벽인 경우 무시
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || maps[nx][ny] == 0)
                continue;
            
            // 방문하지 않은 경우에만 O
            if (dist[nx][ny] == INF) {
                dist[nx][ny] = dist[x][y] + 1;
                
                q.push({nx, ny});
            }
        }
    }
    
    return (dist[n - 1][m - 1] == INF) ? -1 : dist[n - 1][m - 1];
}

int solution(vector<vector<int>> maps) {
    return BFS(maps);
}
