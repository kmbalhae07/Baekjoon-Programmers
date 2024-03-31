#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);

    for(int i=0; i<T; i++){
        char input[1001];
        scanf("%s", input);

        int num = strlen(input) -1;
        printf("%c%c\n", input[0], input[num]);
    }
}
