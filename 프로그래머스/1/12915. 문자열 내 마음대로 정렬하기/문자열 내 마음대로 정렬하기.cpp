#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    //인덱스 n의 문자를 기준으로 정렬 -> 같은 경우 예외처리됨
    sort(strings.begin(), strings.end(), [n](const string& a, const string& b) {
        if (a[n] == b[n]) {
            return a < b;
        }
        return a[n] < b[n];
    });
    return strings;
}
