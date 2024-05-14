#include <stdio.h>
#include <stdlib.h> 

int compare(const void* a, const void* b) { 
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if(num1<num2)
        return -1;
    if(num1>num2)
        return 1;

    return 0;
}

void generatePasswords(int list[], int L, int C, int index, char password[], int start) {
    if (index == L) {
        password[index] = '\0';

        //최소 모음조건 확인
        int check = 0;
        for(int k=0; k<L; k++){
            if(password[k] == 'a' || password[k] == 'e' ||password[k] == 'i' ||password[k] == 'o' ||password[k] == 'u'){
                check++;
            }
        }
        if(check >=1 && L-check >=2) {
            printf("%s\n", password);
        }
        return;
    }

    for (int i = start; i < C; i++) {
        password[index] = list[i] + 'a';
        generatePasswords(list, L, C, index + 1, password, i + 1);
    }
}

int main() {
    int L, C;
    scanf("%d %d", &L, &C);
    getchar();

    int list[C+1];

    //아스키코드값으로 배열에 넣기
    for(int i=0; i<C; i++) {
        char alp;
        scanf(" %c", &alp);
        int temp = alp - 'a';
        list[i] = temp;
    }

    // 배열을 정렬
    qsort(list, C, sizeof(int), compare);

    char password[L]; 
    generatePasswords(list, L, C, 0, password, 0); 
    
    return 0;
}
