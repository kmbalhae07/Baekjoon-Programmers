#include <stdio.h>
#include <stdbool.h>

int list[101][101] = {0};
bool visited[101][101] = {false};
int distance[101][101] = {0};

typedef struct {
    int x, y;
} Point;

void enqueue(Point queue[], int *rear, Point p) {
    queue[*rear] = p;
    (*rear)++;
}

Point dequeue(Point queue[], int *front) {
    return queue[(*front)++];
}

int BFS(int startX, int startY, int N, int M) {
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    Point queue[10001];
    int front = 0, rear = 0;

    enqueue(queue, &rear, (Point){startX, startY});
    visited[startX][startY] = true;
    distance[startX][startY] = 1; // 시작 지점의 거리는 1

    while (front < rear) {
        Point p = dequeue(queue, &front);

        // 목표 지점에 도달하면 거리를 반환
        if (p.x == N-1 && p.y == M-1) {
            return distance[p.x][p.y];
        }

        for (int i = 0; i < 4; i++) {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];

            // 이동할 수 있는 칸 & 방문한 적 없는 곳
            if (nx >= 0 && ny >= 0 && nx < N && ny < M && list[nx][ny] == 1 && !visited[nx][ny]) {
                enqueue(queue, &rear, (Point){nx, ny});
                visited[nx][ny] = true;
                distance[nx][ny] = distance[p.x][p.y] + 1; // 다음 지점의 거리는 현재 지점의 거리 + 1
            }
        }
    }

    return -1; 
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    getchar(); 

    char line[102];
    for (int i = 0; i < N; i++) {
        fgets(line, sizeof(line), stdin);
        for (int k = 0; k < M; k++) {
            list[i][k] = line[k] - '0'; 
        }
    }

    // BFS 시작점 지정
    int result = BFS(0, 0, N, M);

    printf("%d", result);

    return 0;
}
