#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer(n);
    
    for (int i = 0; i < n; i++) {
        int combined = arr1[i] | arr2[i]; // 비트연산자 비교하기
        string row = "";
        
        for (int j = n - 1; j >= 0; j--) { //왼->오
            if (combined & (1 << j)) {
                row += "#";
            } else {
                row += " ";
            }
        }
        answer[i] = row;
    }
    return answer;
}
