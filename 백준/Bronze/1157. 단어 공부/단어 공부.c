#include <stdio.h>
#include <string.h>

// 대문자랑 소문자 아스키코드 32만큼 차이남. (Ex : 97, 65)
int main() {
    char Alpab[1000001];
    int arr[91] = {0};
    fgets(Alpab, sizeof(Alpab), stdin);
    
    int length = strlen(Alpab);
    for(int i=0; i<length; i++) {
        int index = Alpab[i];        
        if(97 <= index && index <= 122) {
            index-=32;
        }

        arr[index] +=1;
    }

    int max_char;
    int max_num = -1;
    for(int i=65; i<92; i++) {
        if(arr[i] > max_num) {
            max_num = arr[i];
            max_char = i;
        }
    }

    int check = 0;
    for(int i=65; i<92; i++) {
        if(arr[i] == max_num) {
            check++;
        }
    }
    if(check >=2) {
        printf("?");
    } else {
        printf("%c", max_char);
    }
}