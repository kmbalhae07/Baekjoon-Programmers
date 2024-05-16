#include <stdio.h>

int Graph[1001][1001] ={0};
int queue[1001];
bool DFSvisited[1001];
bool BFSvisited[1001];

//재귀
void DFS(int V, int N) {
    //방문한 곳 표시 & 출력
    DFSvisited[V] = true;
    printf("%d ", V);
    
    for(int i=1; i<=N; i++) {
        //방문한 적 없을 때 & 가는 길이 있을 때 
        if(!DFSvisited[i] && Graph[V][i] == 1) {
            DFS(i, N);
        }
    }
}

//queue
void BFS(int V, int N){
    int front=0, rear=0, pop;

    printf("%d ", V);
    queue[0] = V;
    rear++;
    BFSvisited[V] = true;

    while(front < rear) {
        pop = queue[front];
        front++;

        for(int i=1; i<=N; i++) {
            if(!BFSvisited[i] && Graph[pop][i] == 1) {
                printf("%d ", i);
                queue[rear] = i;
                rear++;
                BFSvisited[i] = true;
            }
        }
    }
    return;
}

int main() {
    int N, M, V;
    scanf("%d %d %d", &N, &M, &V);

    for(int i=0; i<M; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        Graph[x][y] = 1;
        Graph[y][x] = 1;
    }

    DFS(V, N);
    printf("\n");
    BFS(V, N);
    return 0;
}
