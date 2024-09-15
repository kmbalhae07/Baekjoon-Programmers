import java.util.*;
import java.lang.*;
import java.io.*;

class Main {    
    static int M, N;
    static int[][] farm;
    static int[][] days;  // 익는데 걸리는 일수를 저장하는 배열
    static Queue<int[]> queue = new LinkedList<>();
        
    // 상, 하, 좌, 우 
    static int[] dx = {0, 0, -1, 1};
    static int[] dy = {-1, 1, 0, 0};
    
    // BFS
    public static void bfs() {
        while (!queue.isEmpty()) {
            int[] point = queue.poll();
            int x = point[1];
            int y = point[0];
            
            // 4방향 탐색
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                // 상자 범위를 벗어나지 않고, 익지 않은 토마토일 때
                if (nx >= 0 && ny >= 0 && nx < M && ny < N && farm[ny][nx] == 0) {
                    farm[ny][nx] = 1;  // 토마토를 익게 만듦
                    days[ny][nx] = days[y][x] + 1;  // 걸린 일수를 기록
                    queue.add(new int[]{ny, nx});
                }
            }
        }
    }
    
    public static void main(String[] args) {   
        Scanner sc = new Scanner(System.in);
        
        M = sc.nextInt();
        N = sc.nextInt();
        
        farm = new int[N][M];
        days = new int[N][M];
        
        // 토마토 정보 입력
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                farm[i][j] = sc.nextInt();
                if (farm[i][j] == 1) {
                    queue.add(new int[]{i, j});  // 익은 토마토는 큐에 추가
                }
            }
        }
        
        // BFS로 최소 일수 계산
        bfs();
        
        int maxDays = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                // 익지 않은 토마토가 남아있는 경우
                if (farm[i][j] == 0) {
                    System.out.println("-1");
                    return;
                }
                maxDays = Math.max(maxDays, days[i][j]);
            }
        }
        
        System.out.println(maxDays);
    }
}
