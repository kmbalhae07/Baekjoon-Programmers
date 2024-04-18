#include <stdio.h>
#include <stdbool.h>

// 각 달의 일 수
int days_in_month[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// 2016년 1월 1일부터 해당 날짜까지의 총 일 수
int totalDays(int a, int b) {
    int total = 0;
    for (int i = 0; i < a - 1; i++) {
        total += days_in_month[i];
    }
    total += b;
    return total;
}

char* solution(int a, int b) {
    char* answer = (char*)malloc(sizeof(char) * 4);
    int total = totalDays(a, b);
    
    // 2016년 1월 1일이 금요일 -> case 0 = Fri
    switch (total % 7) {
        case 0: return "THU";
        case 1: return "FRI";
        case 2: return "SAT";
        case 3: return "SUN";
        case 4: return "MON";
        case 5: return "TUE";
        case 6: return "WED";
    }
    
    return answer;
}
