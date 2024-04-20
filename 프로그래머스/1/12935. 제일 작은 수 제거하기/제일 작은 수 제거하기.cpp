#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    vector<int> temp_arr = arr; 
    sort(temp_arr.begin(), temp_arr.end());
    int num = temp_arr[0];
    
    if(temp_arr.size() == 1) {
        answer.push_back(-1); 
    } else {
        for(int i = 0; i < arr.size(); i++) {
            if(num == arr[i]) {
                arr.erase(arr.begin() + i);
            }
        }
        answer = arr; 
    }
    
    return answer;
}
