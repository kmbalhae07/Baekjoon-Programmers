#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);

    for(int i=0; i<T; i++){
        int n;
        char S[21];
        scanf("%d %s", &n, S);

        for(int k=0; k<strlen(S); k++){
            for(int q=0; q<n; q++){
                printf("%c", S[k]);                
            }
        }
        printf("\n");
    }
}