#include <string>
#include <vector>

using namespace std;

int answer = 0;

void DFS(vector<int> numbers, int target, int index, int sum){
    if(index == numbers.size()) {
        if(sum == target) {
            answer++;
        }
        return;
    }
    
    DFS(numbers, target, index+1, sum+numbers[index]);
    DFS(numbers, target, index+1, sum-numbers[index]);
}

int solution(vector<int> numbers, int target) {
    DFS(numbers, target, 0, 0);
    return answer;
}