#include <stdio.h>
#include <string.h>

int main() {
    char c[101];
    scanf("%s", c);
    int last = strlen(c) -1;

    if(last == 0)
        printf("1");
    
    for(int i=0; i<strlen(c); i++) {
        if(c[i] == c[last]) {
            last--;
            if(i==last || last-i == 1) {
                printf("1");
            }
        } else {
            printf("0");
            break;
        }
    }
}