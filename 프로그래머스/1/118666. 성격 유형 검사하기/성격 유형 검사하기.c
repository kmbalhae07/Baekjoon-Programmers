#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct score
{
    int R;
    int T;
    int C;
    int F;
    int J;
    int M;
    int A;
    int N;
};

char* solution(const char* survey[], size_t survey_len, int choices[], size_t choices_len) {
    char* answer = (char*)malloc(sizeof(int) * 4);
    struct score total_score = {0};
    
    for(int i=0; i<choices_len; i++) { 
        int num = 0;
        
        //choice 점수에 따라 더해지는 값, 123
        if(choices[i] == 5 || choices[i] == 3) {
            num = 1;
        } else if(choices[i] == 6 || choices[i] == 2) {
            num = 2;
        } else if(choices[i] == 7 || choices[i] == 1) {
            num = 3;
        } 
        
        //각 영역에 점수
        if(choices[i] < 4) {
            char temp = survey[i][0];  
            switch(temp) {
                case 'R':
                    total_score.R+=num;
                    break;
                case 'T':
                    total_score.T+=num;
                    break;
                case 'C':
                    total_score.C+=num;
                    break;
                case 'F':
                    total_score.F+=num;
                    break;
                case 'J':
                    total_score.J+=num;
                    break;
                case 'M':
                    total_score.M+=num;
                    break;
                case 'A':
                    total_score.A+=num;
                    break;
                case 'N':
                    total_score.N+=num;
                    break;
            }
        } else if(choices[i] > 4) {
            char temp = survey[i][1];
            switch(temp) {
                case 'R':
                    total_score.R+=num;
                    break;
                case 'T':
                    total_score.T+=num;
                    break;
                case 'C':
                    total_score.C+=num;
                    break;
                case 'F':
                    total_score.F+=num;
                    break;
                case 'J':
                    total_score.J+=num;
                    break;
                case 'M':
                    total_score.M+=num;
                    break;
                case 'A':
                    total_score.A+=num;
                    break;
                case 'N':
                    total_score.N+=num;
                    break;
            }
        } 
    }
    
    //각 영역 점수 나온거로 answer 도출
    if(total_score.R > total_score.T)         answer[0] = 'R';
    else if(total_score.R < total_score.T)    answer[0] = 'T';
    else                                      answer[0] = 'R';

    if(total_score.C > total_score.F)         answer[1] = 'C';
    else if(total_score.C < total_score.F)    answer[1] = 'F';
    else                                      answer[1] = 'C';
    
    if(total_score.J > total_score.M)         answer[2] = 'J';
    else if(total_score.J< total_score.M)    answer[2] = 'M';
    else                                      answer[2] = 'J';
    
    if(total_score.A > total_score.N)         answer[3] = 'A';
    else if(total_score.A < total_score.N)    answer[3] = 'N';
    else                                      answer[3] = 'A';
        
    answer[4] = '\0';
    return answer;
}