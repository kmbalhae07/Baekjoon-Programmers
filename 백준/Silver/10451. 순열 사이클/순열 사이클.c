#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int Graph[1001];
bool visited[1001] = {false};

void DFS(int k){
    visited[k] = true;
    int next = Graph[k];

    if(!visited[next]) {
        DFS(next);
    }
}

int main() {
    int answer = 0;
    int T;
    scanf("%d", &T);

    for(int i=0; i<T; i++) {
        int N;
        scanf("%d", &N);

        memset(visited, false, sizeof(visited));
        memset(Graph, 0, sizeof(int));
        answer = 0;
        
        for(int p=1; p<=N; p++) {
            int x;
            scanf("%d", &x);
            Graph[p] = x;
        }

        for(int k=1; k<=N; k++) {
            if(!visited[k]) {
                DFS(k);
                answer++;
            }
        }
        printf("%d\n", answer);
    }

}
