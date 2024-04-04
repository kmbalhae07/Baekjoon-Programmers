#include <stdio.h>
#include <string.h>

//A = 아스키코드 65
int main() {
    char input[16];
    char alpa;
    int num=0;
    scanf("%s", input);

    for(int i=0; i<strlen(input); i++) {
        alpa = input[i];
        if(alpa == 'A' || alpa == 'B' || alpa == 'C') {
            num += 3;
        } else if(alpa == 'D' || alpa == 'E' || alpa == 'F') {
            num += 4;
        } else if(alpa == 'G' || alpa == 'H' || alpa == 'I') {
            num += 5;
        } else if(alpa == 'J' || alpa == 'K' || alpa == 'L') {
            num += 6;
        } else if(alpa == 'M' || alpa == 'N' || alpa == 'O') {
            num += 7;
        } else if(alpa == 'P' || alpa == 'Q' || alpa == 'R' || alpa == 'S') {
            num += 8;
        } else if(alpa == 'T' || alpa == 'U' || alpa == 'V') {
            num += 9;
        } else if(alpa == 'W' || alpa == 'X' || alpa == 'Y' || alpa == 'Z') {
            num += 10;
        }
    }

    printf("%d", num);
}