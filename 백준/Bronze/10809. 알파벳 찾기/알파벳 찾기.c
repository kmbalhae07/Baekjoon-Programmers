#include <stdio.h>
#include <string.h>

int main() {
    char S[101];
    int arr[26];
    scanf("%s", S);

    for (int i = 0; i < 26; i++) {
        arr[i] = -1;
    }

    
    for (int i = 0; i < strlen(S); i++) {
        int index = S[i] - 97; 
        if (arr[index] == -1) { 
            arr[index] = i; 
        }
    }

    for (int i = 0; i < 26; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

}