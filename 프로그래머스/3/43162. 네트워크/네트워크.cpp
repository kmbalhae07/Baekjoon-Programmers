#include <string>
#include <vector>

using namespace std;

void dfs(int node, vector<vector<int>> computers, vector<bool>& visited) {
    visited[node] = true;
    
    for(int i=0; i<computers.size(); i++) {
        //node와 i가 연결되어있을 때 & 방문한 적 없으면 재귀
        if(computers[node][i] == 1 && !visited[i]) {
            dfs(i, computers, visited);
        }
        //위 조건 X 걍 종료 -> answer++;
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
     vector<bool> visited(n, false);    
    
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            dfs(i, computers, visited);
            answer++;
        }
    }
    
    return answer;
}