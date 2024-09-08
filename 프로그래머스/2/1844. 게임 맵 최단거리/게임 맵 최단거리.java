import java.util.*;

class Solution {
    static final int INF = 987654321;

    public int BFS(int[][] maps) {
        int n = maps.length;
        int m = maps[0].length;
        int[][] dist = new int[n][m];
        for (int[] row : dist) {
            Arrays.fill(row, INF);
        }
        
        Queue<int[]> q = new LinkedList<>();
        
        // 방향 상수 정의
        int[] dx = {1, -1, 0, 0};
        int[] dy = {0, 0, 1, -1};
        
        q.offer(new int[]{0, 0});
        dist[0][0] = 1;
        
        while (!q.isEmpty()) {
            int[] pos = q.poll();
            int x = pos[0];
            int y = pos[1];
            
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
                    q.offer(new int[]{nx, ny});
                }
            }
        }
        
        return (dist[n - 1][m - 1] == INF) ? -1 : dist[n - 1][m - 1];
    }

    public int solution(int[][] maps) {
        return BFS(maps);
    }
}
