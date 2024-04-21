#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    int size = commands.size();
    
    for(int i=0; i<size; i++) {
        //i번부터 j번째 숫자 제외 자르기
        vector<int> temp(array.begin() + commands[i][0] - 1, array.begin() + commands[i][1]);

        //배열 정리하기
        sort(temp.begin(), temp.end());
        
        //answer에 답
        answer.resize(i + 1);
        answer[i] = temp[commands[i][2] -1];
    }
    
    return answer;
}