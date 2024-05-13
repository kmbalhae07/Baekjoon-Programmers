#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int count_p = 0, count_y = 0;
    
    //소문자로
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    
    for(char ch : s) {
        if(ch == 'p') 
            count_p++;
        else if(ch == 'y') 
            count_y++;
    }
    
    if(count_p == count_y) 
        answer = true;
    else
        answer = false;

    return answer;
}