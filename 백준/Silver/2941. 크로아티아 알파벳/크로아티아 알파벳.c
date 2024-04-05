#include <stdio.h>
#include <string.h>

int main() {
    char input[101];
    scanf("%s", input);

    int total = strlen(input);
    int num = 0;
    int length = strlen(input);

    for(int i=0; i<length; i++) {
        if(input[i] == '=') {
            if(input[i-1] == 'c') {
                total-=2;
                num++;
            } else if(input[i-1] == 'z' && input[i-2] == 'd') {
                total-=3;
                num++;
            } else if(input[i-1] == 's') {
                total-=2;
                num++;
            } else if(input[i-1] == 'z') {
                total-=2;
                num++;
            }
        } else if(input[i] == '-') {
            if(input[i-1] == 'c') {
                total-=2;
                num++;
            } else if(input[i-1] == 'd') {
                total-=2;
                num++;
            }
        } else if(input[i] == 'j') {
            if(input[i-1] == 'l') {
                total-=2;
                num++;
            } else if(input[i-1] == 'n') {
                total-=2;
                num++;
            }
        }
    }

    printf("%d", total + num);
}