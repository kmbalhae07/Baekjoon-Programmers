#include <stdio.h>

int main() {
    char S[1001];
    int i;

    scanf("%s\n%d", S, &i);
    printf("%c", S[i-1]);
}