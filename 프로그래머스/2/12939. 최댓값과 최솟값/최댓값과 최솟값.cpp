#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> numbers;
    stringstream ss(s);
    string token;

    // 공백을 기준으로 문자열 분할하여 숫자 추출
    while (getline(ss, token, ' ')) {
        if (token != "")
            numbers.push_back(stoi(token));
    }

    sort(numbers.begin(), numbers.end());

    answer += to_string(numbers.front());
    answer += " ";
    answer += to_string(numbers.back());
    
    return answer;
}
