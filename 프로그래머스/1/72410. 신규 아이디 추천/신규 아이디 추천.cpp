#include <string>
#include <vector>
#include <algorithm>
#include <ctype.h>

using namespace std;

string solution(string new_id) {
    string answer = "";
    //1단계
    transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower);
    
    //2단계
    new_id.erase(remove_if(new_id.begin(), new_id.end(), [](char c) {
        return !(isalnum(c) || c == '-' || c == '_' || c == '.');
    }), new_id.end());
    
    //3단계
    string temp;
    for (char c : new_id) {
        if (temp.empty() || temp.back() != '.' || c != '.') {
            temp.push_back(c);
        }
    }
    new_id = temp;
    
    // 4단계
    if (!new_id.empty() && new_id.front() == '.') {
        new_id.erase(new_id.begin());
    }
    if (!new_id.empty() && new_id.back() == '.') {
        new_id.pop_back();
    }
    
    // 5단계
    if (new_id.empty()) {
        new_id = "a";
    }
    
    // 6단계
    if (new_id.length() >= 16) {
        new_id = new_id.substr(0, 15);
        if (new_id.back() == '.') {
            new_id.pop_back();
        }
    }
    
    // 7단계
    while (new_id.length() <= 2) {
        new_id += new_id.back();
    }
    
    answer = new_id;
    return answer;
}