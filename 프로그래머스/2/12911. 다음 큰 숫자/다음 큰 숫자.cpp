#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int cnt = 0;
    int original_n = n;
    
    // n의 2진수 1개수 구하기
    while(n != 0) {
        if(n % 2 == 1) {
            cnt++;
        }
        n /= 2;
    }
    
    answer = original_n + 1;
    while(1) {
        int check = 0;
        int temp = answer;
        while(temp != 0) {
            if(temp % 2 == 1) {
                check++;
            }
            temp /= 2;
        }
        
        if(check == cnt) {
            break;
        }
        
        answer++;
    }
    
    return answer;
}
