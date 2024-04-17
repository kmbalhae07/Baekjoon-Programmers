#include <string>
#include <cmath>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int *arr = new int[dartResult.length()];
    char single = 'S';
    char doubles = 'D';
    char triple = 'T';
    
    int temp = 0;
    for(int i=0; i<dartResult.length(); i++) {
        if(dartResult[i] == single) {
            if(dartResult[i-1] == '0' && dartResult[i-2] == '1') {
                arr[temp] = 10;
                temp++;
            } else {
                arr[temp] = dartResult[i-1] - '0';
                temp++;
            }
        } else if(dartResult[i] == doubles) {
            if(dartResult[i-1] == '0' && dartResult[i-2] == '1') {
                arr[temp] = 100;
                temp++;
            } else {
                arr[temp] = pow(dartResult[i-1] - '0', 2);
                temp++;;
            }
        } else if(dartResult[i] == triple) {
            if(dartResult[i-1] == '0' && dartResult[i-2] == '1') {
                arr[temp] = 1000;
                temp++;
            } else {
                arr[temp] = pow(dartResult[i-1] - '0', 3);
                temp++;
            }
        } else if(dartResult[i] == '*' && temp == 1) {
            arr[temp-1] *= 2;
        } else if(dartResult[i] == '*' && temp != 1) {
            arr[temp-1] *= 2;
            arr[temp-2] *= 2;
        } else if(dartResult[i] == '#') {
            arr[temp-1] *= (-1);
        }
    }
    
    for(int k=0; k<temp; k++) {
        answer += arr[k];
    }
    
    return answer;
}