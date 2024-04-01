#include <stdio.h>
#include <string.h>

int main() {
    char sentence[1000001];
    scanf("%[^\n]s", sentence);
    int num = 1;

    for(int i=0; i<strlen(sentence); i++) {
        if(sentence[i] == ' ') {
            num++;
        }
    }

    if(sentence[0] == ' ') {
        num-=1;
    }
    if(sentence[strlen(sentence)-1] == ' ') {
        num-=1;
    }

    printf("%d", num);
}